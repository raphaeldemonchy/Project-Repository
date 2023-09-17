import React, { useState, useContext } from 'react';
import HomeScreen from './HomeScreen';
import {StyleSheet,
  TextInput,
  View,
  Image,
  Text,
  TouchableOpacity,
  Font,
  SafeAreaView,
  ScrollView,
  ImageBackground,
  Dimensions,
  Alert,
  Animated,
  ActivityIndicator,
} from 'react-native';
import { useEffect, useRef } from 'react';
import { useNavigation } from '@react-navigation/native';
import axios from 'axios';
import Icon from 'react-native-vector-icons/MaterialCommunityIcons';
import Icon2 from 'react-native-vector-icons/MaterialIcons';
import { MyContext} from '../utils/Provider'
import { Buffer } from 'buffer';
import { MyWidgetContext } from '../utils/WidgetProvider';
import * as Location from 'expo-location';

window.userToken = '';

const LoginScreen = () => {
  const { updateEmployeeData } = useContext(MyContext);
  const { updateEmployeeTmpData } = useContext(MyContext);
  const { updateConversations } = useContext(MyContext);
  const { updateProfileData } = useContext(MyContext);
  const { getEmployeesData } = useContext(MyContext);
  const { updateCoordsData } = useContext(MyContext);
  const { updateCeoData } = useContext(MyContext);
  const { updateWeatherData } = useContext(MyContext);
  const { updateNewsData } = useContext(MyContext);
  const { updateEventsData } = useContext(MyContext);
  const { updateConversationsData } = useContext(MyContext);
  const { data, setData } = useContext(MyContext);
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [errorMessage, setErrorMessage] = useState('');

  const [isPasswordVisible, setPasswordVisible] = useState(false);
  const [isActivityIndicator, setActivityIndicator] = useState(false);
  const togglePasswordVisibility = () => {
    setPasswordVisible(!isPasswordVisible);
  };

  const [isEmailFocused, setIsEmailFocused] = useState(false);
  const [isPasswordFocused, setIsPasswordFocused] = useState(false);
  const handleEmailFocus = () => {
    setIsEmailFocused(true);
    setIsPasswordFocused(false);
  };
  const handlePasswordFocus = () => {
    setIsPasswordFocused(true);
    setIsEmailFocused(false);
  };
  const emailBorderColor = isEmailFocused ? '#d9d9d9' : '#d9d9d9';
  const passwordBorderColor = isPasswordFocused ? '#d9d9d9' : '#d9d9d9';

  const [scrollY] = useState(new Animated.Value(0));
  const navigation = useNavigation();

  const {elements, newElement} = useContext(MyWidgetContext);
  const { setElem } = useContext(MyWidgetContext);
  let tmp = null;


  const [location, setLocation] = useState(null);

  const getLoc = async () => {
    let { status } = await Location.requestForegroundPermissionsAsync();
    if (status !== 'granted') {
      return;
    }
    let location = await Location.getCurrentPositionAsync({});
    updateCoordsData(location.coords);
    setLocation(location);
    return (location);
  }

  const getRealWeather = async (latitude, longitude) => {
    const options = {
      method: 'GET',
      url: 'https://weatherapi-com.p.rapidapi.com/current.json',
      params: {q: `${latitude},${longitude}`},
      headers: {
        'X-RapidAPI-Key': '4351ecdcfamshf16630a57a9b07cp121108jsnac8912d5be05',
        'X-RapidAPI-Host': 'weatherapi-com.p.rapidapi.com'
      }
    };
    const response = await axios.request(options);
    await updateWeatherData(response.data);
    return
  }

  const getNews = async () => {
      await axios.get('https://newsdata.io/api/1/news?apikey=pub_29019d0c4058f6b09dcfbf23da9d615c458c3&q=cyber%20security&language=en').then(response => {
        const dataNews = response.data;
        updateNewsData(dataNews.results);
      }).catch(error => {
        console.log(error);
      });
    }


  const handlePress = (email, password) => {
    const body = {
      email: email,
      password: password
    }
    const headers = {
        'accept': 'application/json',
        'X-Group-Authorization': 'ce4b22bb3315b112d58013a20f09de9f',
        'Content-Type': 'application/json'
    };
    axios.post('https://masurao.fr/api/employees/login', {
      email: email,
      password: password
    }, {headers}).then(response => {
        token = response.data.access_token;
        console.log(token);
    axios.post('http://10.79.216.104:1234/employee/login', body).then(async response => {
      if (response.status === 200) {
        console.log('START')
        console.log('getEmployee');
        const employees = await getEmployees();
        console.log('updateProfileData');
        await updateProfileData(response.data);
        console.log('getConversation');
        await getConversations(response.data.id);
        console.log('getLoc');
        const loc = await getLoc();
        console.log('getRealWeather');
        await getRealWeather(loc.coords.latitude, loc.coords.longitude)
        await getNews();
        tmp = await employees.find(employee => {return(employee.fonction == 'CEO');});
        updateCeoData(tmp);
        getRdv(response.data.id)
        console.log(tmp.name + ' ' + tmp.surname + ' ' + tmp.email + ' ' + tmp.fonction);
        console.log('FINISH')
        navigation.navigate('HomeScreen');

        const data_widget = ([
          {title: 'Trombinoscope', id: '0', type: 'rectangle', borderColor: '#e6e6ff', backgroundColor: '#ccccff', width: '95%', height: 200, size: '',
            item: () => {
                return (
                  <View style={{padding: '4%'}}>
                    <Text style={{fontSize: 30, fontWeight: 'bold'}} >Trombinoscope</Text>
                    <Text style={{fontSize: 14, padding: '3%'}} >Discover the team</Text>
                    <View style={{flexDirection: 'row', justifyContent: 'space-between',
                  backgroundColor: '#b3b3ff', height: '50%', width: '80%', marginTop: '2%', alignSelf: 'center', borderRadius: 15}}>
                      <Image style={styles.employeeImage} source={{ uri: tmp.imageUrl }} />
                    <View style={{padding: '3%', right: '85%', top: '5%'}}>
                      <Text style={{fontWeight: 'bold'}}>{tmp.name + ' ' + tmp.surname}</Text>
                      <Text>{tmp.fonction}</Text>
                    </View>
                    </View>
                  </View>
                );
              }
            },
            {title: '', id: '', type: 'none', color: '', borderColor: '', width: '', height: '', size: '', item: () => {}},
          ]);
          setElem(data_widget);

      }
    }).catch(error => {
      console.log(error);
      if (error.response.status === 401) {
        console.log("Invalid Email and Password combination.");
        setErrorMessage("Invalid Email and Password combination.");
      }
      if (error.response.status === 422) {
        console.log("Server error.");
        setErrorMessage("Server error.");
      }
    });
  })
  };

  const getEmployees = async () => {
    const res = await axios.get('http://10.79.216.104:1234/employees').then(async response => {
      const employees = response.data;
      updateEmployeeData(employees);
      updateEmployeeTmpData(employees);
      return (employees);
    }).catch(error => {
      console.log(error);
    });
    return(res);
  }

  const getConversations = async (id) =>
  {
    try {
      const req_url = "http://10.79.216.104:1234/conversations/employee/" + id
      let res = await axios.get(req_url);
      updateConversationsData(res.data)
      return res.data
    } catch (e) {
      console.error("erreur lors de la recuperation des conversations: ", e)
    }
  }

  const getRdv = async (id_employee) => {
    try {
      const req_url = "http://10.79.216.104:1234/events/" + id_employee
      let res = await axios.get(req_url);
      console.log(res.data);
      updateEventsData(res.data)
      return res.data
    } catch (e) {
      console.error("erreur lors de la recuperation des events: ", e)
    }
  }

  const scrollViewRef = useRef();
  const [userScrolled, setUserScrolled] = useState(false);

  const headerOpacity = scrollY.interpolate({
    inputRange: [10, 300],
    outputRange: [1, 0],
    extrapolate: 'clamp',
  });

  const contentOpacity = scrollY.interpolate({
    inputRange: [200, 700],
    outputRange: [0, 1],
    extrapolate: 'clamp',
  });

  const scrollToBottom = () => {
    if (scrollViewRef.current && userScrolled) {
      const scrollYValue = scrollY._value;
      const scrollDuration = 500;

      Animated.timing(scrollY, {
        toValue: scrollYValue + 6000,
        duration: scrollDuration,
        useNativeDriver: false,
      }).start();
    }
  };

  useEffect(() => {
    if (userScrolled) {
      scrollToBottom();
    }
  }, [userScrolled]);

  const handleScroll = (event) => {
    const yOffset = event.nativeEvent.contentOffset.y;
    if (yOffset > 50) {
      setUserScrolled(true);
    }
  };

  useEffect(() => {
    Animated.timing(scrollY, {
      toValue: 100,
      duration: 500,
      useNativeDriver: false,
    }).start();
  }, []);

  return (
    <ImageBackground source={require('../assets/background.jpg')} style={styles.backgroundImage}>
      <SafeAreaView style={styles.container}>
        <ScrollView contentContainerStyle={{
          paddingTop: '15%',
          paddingHorizontal: '8%',
          paddingBottom: '140%',
        }}
        ref={scrollViewRef}
        onScroll={Animated.event(
          [{ nativeEvent: { contentOffset: { y: scrollY } } }],
          { useNativeDriver: false }
        )}
        scrollEventThrottle={16}
        onScrollBeginDrag={(event) => handleScroll(event)}
        >
        <Animated.View style={{ opacity: headerOpacity }}>
          <View style={{ height: '50%', width: '90%', marginTop: '20%' ,alignSelf: 'center', marginBottom: '20%'}}>
            <Image source={require('../assets/CollabZ.png')} style={{ flex: 1, width: '90%', height: '90%', resizeMode: 'contain', alignSelf:'center', transform: [{ scale: 2.5 }]}} />
          </View>
        </Animated.View>
          <Animated.Text style={{fontSize: 15, color: '#000000', marginBottom: '30%', fontWeight: 'bold', alignSelf: 'center', opacity: headerOpacity}}>
            Want to login ? Swipe up ! ⬆️
          </Animated.Text>

          <Animated.View style={{ opacity: contentOpacity }}>
          <Text style={{fontSize: 50, color: '#000000', marginBottom: 20, fontWeight: 'bold'}}>
            Login
          </Text>
          <Text style={{fontSize: 20, color: '#333333', marginBottom: 50}}>
            Welcome back ! 💻
          </Text>

          {errorMessage ? (
            <Text style={styles.errorMessage}>{errorMessage}</Text>
          ) : null}

          <View style={[styles.inputEmailContainer, { borderColor: emailBorderColor }]}>
            <TextInput
              placeholder="Email"
              value={email}
              style={styles.textBox}
              onChangeText={(text) => setEmail(text)}
              onFocus={handleEmailFocus}
            />
            <Icon name="email-outline" size={20} color="#000000" style={{ paddingHorizontal: '2%'}}/>
          </View>

          <View style={[styles.inputPasswordContainer, { borderColor: passwordBorderColor }]}>
            <TextInput
              placeholder="Password"
              value={password}
              style={styles.textBox}
              secureTextEntry={!isPasswordVisible}
              onChangeText={(text) => setPassword(text)}
              onFocus={handlePasswordFocus}
            />
            <TouchableOpacity onPress={togglePasswordVisibility} style={styles.iconContainer}>
              <Icon2
                name={isPasswordVisible ? 'visibility' : 'visibility-off'}
                size={20}
                color="#000000"
              />
            </TouchableOpacity>
          </View>
          <TouchableOpacity onPress={() => { handlePress(email, password), setActivityIndicator(true)}} style={styles.loginBtn}>
          {isActivityIndicator ? <ActivityIndicator size="small" color="white" /> :
            <Text style={{fontWeight: 'bold', fontSize: 15, color: '#fff'}}>
              LETS GO ! 🚀
            </Text>}
          </TouchableOpacity>
          </Animated.View>
        </ScrollView>

      </SafeAreaView>
    </ImageBackground>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: 'rgba(0,0,0,0,5)',
  },
  backgroundImage: {
    flex: 1,
    resizeMode: 'cover',
  },
  inputEmailContainer: {
    marginTop: '10%',
    borderWidth: '2%',
    borderRadius: 15,
    backgroundColor: '#ffffff',
    height: '9%',
    flexDirection: 'row',
    justifyContent: 'center',
    alignItems: "center",
  },
  inputPasswordContainer: {
    marginTop: '10%',
    borderWidth: '2%',
    borderRadius: 15,
    height: '9%',
    backgroundColor: '#ffffff',
    flexDirection: 'row',
    justifyContent: 'center',
    alignItems: "center",
  },
  loginBtn: {
    width: "80%",
    borderRadius: 15,
    height: '8%',
    alignItems: "center",
    justifyContent: "center",
    marginTop: '30%',
    backgroundColor: "#a64dff",
    alignSelf: 'center',
  },
  textBox:{
    margin: '3%',
    borderRadius: 15,
    padding: '2%',
    width:'80%',
    alignItems: "center",
    height: '80%',
  },
  iconContainer: {
    padding: '2%',
  },
  errorMessage: {
    color: '#ff4d4d',
    padding: '2%',
    paddingHorizontal: '13%',
    fontWeight: 'bold',
    alignItems: 'center',
    justifyContent: 'center',
    fontSize: 13,
  },
  employeeImage: {
    width: '30%',
    height: '100%',
    borderRadius: 15,
  },
});

export default LoginScreen;