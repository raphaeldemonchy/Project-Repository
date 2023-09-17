import React, { useState, useContext, useEffect } from 'react';
import {TextInput,
  Image,
  TouchableOpacity,
  Font,
  SafeAreaView,
  ScrollView,
  ImageBackground,
  Dimensions,
  Alert,
} from 'react-native';
import { StyleSheet, View, Text, Switch, SectionList } from "react-native";
import MaterialCommunityIconsIcon from "react-native-vector-icons/MaterialCommunityIcons";
import IoniconsIcon from "react-native-vector-icons/Ionicons";
import CupertinoSearchBarBasic from "./CupertinoSearchBarBasic";
import { useNavigation } from '@react-navigation/native';
import Icon from 'react-native-vector-icons/FontAwesome';
import Icon5 from 'react-native-vector-icons/FontAwesome5';
import { MyWidgetContext } from '../utils/WidgetProvider';
import { Dropdown } from 'react-native-element-dropdown';
import AntDesign from '@expo/vector-icons/AntDesign';
import MapView, { Marker } from 'react-native-maps';
import { MyContext} from '../utils/Provider'
import * as Location from 'expo-location';
import Icon2 from 'react-native-vector-icons/Feather';
import { LinearGradient } from "expo-linear-gradient";
import RNPickerSelect from 'react-native-picker-select';
import axios from 'axios';
import { FlatList } from 'react-native-gesture-handler';
import IconE from 'react-native-vector-icons/MaterialIcons';




function AddWidgetScreen(props) {
  const { data, setData } = useContext(MyContext);
  const [dataWeather, setDataWeather] = useState({icon: '', text: '', temp: 0, city: '', temp_max: 0, temp_min: 0});
  const [expandedId, setExpandedId] = useState(null);

  const coordinate = {
    latitude: data.coords.latitude,
    longitude: data.coords.longitude,
  };

  ///////////////////////////////////////////////

  //mapWidget

  ///////////////////////////////////////////////

  const mapWidget = () => {
    return(
        <MapView
          style={{ width: '100%', height: '100%', borderRadius: 15}}
          initialRegion={{
            latitude: coordinate.latitude,
            longitude: coordinate.longitude,
            latitudeDelta: 0.01,
            longitudeDelta: 0.01,
          }}>
            <Marker coordinate={coordinate} />
          </MapView>
    );
  }

  ///////////////////////////////////////////////

  //trombiWidget

  ///////////////////////////////////////////////

  const trombiWidget = () => {
    return (
      <View style={{padding: '4%'}}>
        <Text style={{fontSize: 30, fontWeight: 'bold', color: '#17174f'}} >Trombinoscope</Text>
        <Text style={{fontSize: 14, padding: '3%', color: '#17174f'}} >Discover the team</Text>
        <View style={{flexDirection: 'row', justifyContent: 'space-between',
      backgroundColor: '#b3b3ff', height: '50%', width: '80%', marginTop: '2%', alignSelf: 'center', borderRadius: 15}}>
          <Image style={styles.employeeImage} source={{ uri: data.ceo.imageUrl }} />
        <View style={{padding: '3%', right: '85%', top: '5%', color: '#17174f'}}>
          <Text style={{fontWeight: 'bold', color: '#17174f'}}>{data.ceo.name + ' ' + data.ceo.surname}</Text>
          <Text style={{color: '#17174f'}}>{data.ceo.fonction}</Text>
        </View>
        </View>
      </View>
    );
  };

  const trombiWidgetSquare = () => {
    return (
      <View style={{padding: '8%'}}>
        <Text style={{fontSize: 15, fontWeight: 'bold'}} >Trombinoscope</Text>
        <Text style={{fontSize: 14, padding: '3%'}} >Statistics</Text>
        <View style={{flexDirection: 'row', justifyContent: 'space-between'}}>
          <Text style={{fontSize: 40, padding: '3%', fontWeight: 'bold'}} >{data.employee.length}</Text>
          <Text style={{fontSize: 12, padding: '3%', top: '15%'}} >Members</Text>
        </View>
        <View style={{flexDirection: 'row', justifyContent: 'space-between', bottom: '8%'}}>
          <Text style={{fontSize: 40, padding: '3%', fontWeight: 'bold'}} >1</Text>
          <Text style={{fontSize: 12, padding: '3%', top: '15%'}} >Ceo</Text>
        </View>
      </View>
    );
  };

  ///////////////////////////////////////////////

  //weatherWidget

  ///////////////////////////////////////////////

  const weatherWidgetMiddle = () => {
    let iconName = data.weather.current.is_day === 0 ? "moon" : "sun";
    return (
      <View style={{padding: '4%'}}>
        <View style={{flexDirection: 'row', justifyContent: 'space-between'}}>
          <View>
          <View style={{flexDirection: 'row'}}>
            <Text style={{fontSize: 15, fontWeight: 'bold', color: '#4d1a00'}} >{data.weather.location.name + ',' + data.weather.location.country}    </Text>
            <Icon style={{ color: "black", top: '1%', color: '#4d1a00'}} name="location-arrow" size={13} />
          </View>
            <Text style={{fontSize: 14, color: '#4d1a00'}} >{data.weather.location.region}</Text>
            <Text style={{fontSize: 14, color: '#4d1a00'}} >{'Weather ' + data.weather.current.condition.text}</Text>
          </View>
          <View style={{flexDirection: 'column'}}>
            <Text style={{fontSize: 25, fontWeight: 'bold', color: '#4d1a00'}} >{data.weather.current.temp_c+'°C'}    </Text>
            <Icon2 style={{ color: "black", padding: '5%', color: '#4d1a00'}} name={iconName} size={30} />
          </View>
        </View>
      </View>
    );
  }

  const weatherWidgetSquare = () => {
    let iconName = data.weather.current.is_day === 0 ? "moon" : "sun";
    return (
      <View style={{padding: '7%'}}>
        <View style={{flexDirection: 'column', justifyContent: 'space-between'}}>
          <View>
          <View style={{flexDirection: 'row'}}>
            <Text style={{fontSize: 15, fontWeight: 'bold'}} >{data.weather.location.name}    </Text>
            <Icon style={{ color: "black", top: '1%'}} name="location-arrow" size={13} />
          </View>
          <View style={{flexDirection: 'row', alignSelf: 'center', padding: '10%'}}>
            <Text style={{fontSize: 30, fontWeight: 'bold'}} >{data.weather.current.temp_c+'°C'}    </Text>
            <Icon2 style={{ color: "black"}} name={iconName} size={35} />
          </View>
            <Text style={{fontSize: 14}} >{data.weather.location.region}</Text>
            <Text style={{fontSize: 14}} >{'Weather ' + data.weather.current.condition.text}</Text>
          </View>
        </View>
      </View>
    );
  }

  ///////////////////////////////////////////////

  //CurrencyWidget

  ///////////////////////////////////////////////

  const [fromCurrency, setFromCurrency] = useState('EUR');
  const [toCurrency, setToCurrency] = useState('USD');
  const [newCurrency, setNewCurrency] = useState('');
  const [result, setToResult] = useState('');
  const [amount, setAmount] = useState('');
  const handleConvert = async (amount) => {
    const options = {
      method: 'GET',
      url: 'https://currency-converter-by-api-ninjas.p.rapidapi.com/v1/convertcurrency',
      params: {
        have: fromCurrency,
        want: toCurrency,
        amount: amount
      },
      headers: {
        'X-RapidAPI-Key': '4351ecdcfamshf16630a57a9b07cp121108jsnac8912d5be05',
        'X-RapidAPI-Host': 'currency-converter-by-api-ninjas.p.rapidapi.com'
      }
    };
    try {
      const response = await axios.request(options);
      console.log(response.data);
      setToResult(response.data.new_amount);
      setNewCurrency(response.data.new_currency);
    } catch (error) {
      console.error(error);
    }
  };

  const currencies = [
    { label: 'USD', value: 'USD' },
    { label: 'EUR', value: 'EUR' },
    { label: 'JPY', value: 'JPY' },
    { label: 'GBP', value: 'GBP' },
    { label: 'AUD', value: 'AUD' },
    { label: 'CAD', value: 'CAD' },
  ];

  const currencyWidget = () => {
    return (
      <LinearGradient style={{flex: 1, borderRadius: 15}} colors={['#4d4d4d', 'black']}>
        <View style={{ flexDirection: 'row', alignItems: 'center', justifyContent: 'space-between', paddingBottom: '2%'}}>
          <Text style={{ fontSize: 20, marginLeft: '5%', marginRight: '5%', marginTop: '5%',  color: '#fff' }}>Currency Converter</Text>
          <Image source={require('../assets/money-exchange.png')} style={{ width: '12%', height: '100%', marginTop: '5%', marginLeft: '5%', marginRight: '5%', paddingBottom: '2%'}} />
        </View>
        <View style={{ flexDirection: 'row', alignItems: 'center', justifyContent: 'center' }}>
        <View style={styles.pickerContainer}>
          <RNPickerSelect
            items={currencies}
            onValueChange={(value) => setFromCurrency(value)}
            value={fromCurrency}
            style={{fontWeight: 'bold', fontSize: 20}}
          />
        </View>
        <Text style={{ fontSize: 20, margin: '5%', paddingHorizontal: '5%', color: 'white' }}>-></Text>
        <View style={styles.pickerContainer}>
          <RNPickerSelect
            items={currencies}
            onValueChange={(value) => setToCurrency(value)}
            value={toCurrency}
          />
        </View>
        </View>
        <View style={{ flexDirection: 'row', alignItems: 'center', justifyContent: 'space-between', paddingHorizontal: '10%'}}>
          <TextInput
            placeholder="Enter amount..."
            value={amount}
            onChangeText={(text) => setAmount(text)}
            keyboardType="numeric"
            style={{
              padding: '5%',
              marginBottom: '2%',
              fontSize: 14,
              width: '50%',
              height: '50%',
              backgroundColor: 'white',
              borderRadius: 10,
              marginTop: '2%',
              alignSelf: 'center',
            }}
          />
           <TouchableOpacity style={styles.convertButton} onPress = {() => handleConvert(amount)}>
            <Text style={styles.buttonText}>Convert</Text>
          </TouchableOpacity>
        </View>
        <Text style={{fontSize: 16, fontWeight: 'bold', paddingHorizontal: '5%', color: 'white'}}>Result: {result.new_amount + ' ' + newCurrency}</Text>
    </LinearGradient>
    );
  }

  ///////////////////////////////////////////////

  //News

  ///////////////////////////////////////////////
  const newsWidget = () => {
    const sections = [
      {
        title: 'News',
        data: data.news.map(item => ({ title: item.title })),
      },
      // Ajoutez d'autres sections si nécessaire
    ];
    console.log(data.news[10]);
    return (
      <View style={{padding: '7%', width: '100%', height: '100%', backgroundColor: '#f5e6ff', borderRadius: 12}}>
          <View style={{flexDirection: 'row', paddingBottom: '2%'}}>
            <Text style={{fontSize: 18, fontWeight: 'bold', color: '#29293d'}} >Lastest News    </Text>
            <Icon5 style={{ color: "#29293d" }} name="newspaper" size={20} />
          </View>
          <View style={{flexDirection: 'row', paddingBottom: '2%'}}>
            <Text style={{fontSize: 14, padding: '1%', color: '#29293d'}} >{'- ' + data.news[5].title}</Text>
          </View>
        <Text style={{fontSize: 14, padding: '1%', color: '#29293d'}} >{'- ' + data.news[1].title}</Text>
      </View>
    );
  }

  ///////////////////////////////////////////////

  //Chat gpt

  ///////////////////////////////////////////////

  const gptWidget = () => {
    return (
      <View style={{alignItems: 'center', justifyContent: 'center'}}>
        <Text style={{fontSize: 30, padding: '3%', fontWeight: 'bold'}}>Chat GPT</Text>
        <View style={{ flexDirection: 'row', alignItems: 'center', justifyContent: 'space-between', bottom: '5%'}}>
          <Image source={require('../assets/gptIcon.png')} style={{width: '22%', height: '100%', marginTop: '20%', marginLeft: '5%', marginRight: '5%', paddingBottom: '2%'}} />
          <Text style={{ fontSize: 15, marginLeft: '5%', marginRight: '5%', marginTop: '5%',  color: 'black', top: '7%'}}>Coming Soon...</Text>
        </View>
      </View>
    );
  }

  ///////////////////////////////////////////////

  //Event Widget

  ///////////////////////////////////////////////
  console.log(data.events[0].organizer.name);
  const eventsWidget = () => {
    return (
      <View style={{padding: '4%'}}>
        <View style={{flexDirection: 'row', justifyContent: 'space-between'}}>
          <View>
          <View style={{flexDirection: 'row'}}>
            <Text style={{fontSize: 15, fontWeight: 'bold', color: '#4d1a00'}} >Events    </Text>
            <IconE style={{ color: "black", top: '1%', color: '#4d1a00'}} name="event" size={15} />
          </View>
            <Text style={{fontSize: 14, color: '#4d1a00'}} >{'By ' + data.events[0].organizer.name + ' ' + data.events[0].organizer.surname}</Text>
            <Text style={{fontSize: 14, color: '#4d1a00'}} >{'Object: ' + data.events[0].title}</Text>
          </View>
          <View style={{flexDirection: 'column'}}>
            <Text style={{fontSize: 15, fontWeight: 'bold', color: '#4d1a00', left: '7.5%'}} >{'Start: ' + data.events[0].dateStart.slice(0, 10)}    </Text>
            <Text style={{fontSize: 15, fontWeight: 'bold', color: '#4d1a00', left: '14%'}} >{'End: ' + data.events[0].dateEnd.slice(0, 10)}</Text>
          </View>
        </View>
      </View>
    );
  }







  const [switchValue, setSwitchValue] = useState(false);

  const {elements, newElement} = useContext(MyWidgetContext);
  const { addWidget } = useContext(MyWidgetContext);

  const navigation = useNavigation();
  const handleBackButtonPress = () => {
      navigation.goBack();
  };

  // useEffect(() => {
  //   addWidget(data);
  // }, []);

  // const test = () => {
  //   return (
  //     <View>
  //       <Text style={{fontSize: 16}} >PAZAZAZAZAZAZAZ</Text>
  //     </View>
  //   );
  // }

  const [selectedRectangles, setSelectedRectangles] = useState([]);
  const [widgetModel, setWidgetModel] = useState({
    title: '',
    id: '',
    type: '',
    borderColor: '',
    backgroundColor: '',
    width: '',
    height: '',
    size: '',
    item: () => {}
  });

  const [value, setValue] = useState(null);

  const handleRectangleClick = (id) => {

    setSelectedRectangles(id);
    const newWidgetModel = { ...widgetModel };
    newWidgetModel.id = new Date().getTime();

    if (id === 1) {
      newWidgetModel.type = 'rectangle';
      newWidgetModel.width = '95%';
      newWidgetModel.height = 200;
      newWidgetModel.backgroundColor = '#ccccff';
      newWidgetModel.borderColor = '#e6e6ff';
      newWidgetModel.item = () => {};
      setValue(null);
    } else if (id === 2) {
      newWidgetModel.type = 'middleRectangle';
      newWidgetModel.width = '95%';
      newWidgetModel.height = 100;
      newWidgetModel.backgroundColor = '#ffccb3';
      newWidgetModel.borderColor = '#ffddcc';
      newWidgetModel.item = () => {};
      setValue(null);
    } else if (id === 3) {
      newWidgetModel.type = 'square';
      newWidgetModel.size = 170;
      newWidgetModel.backgroundColor = '#b3e0ff';
      newWidgetModel.borderColor = '#ccebff';
      newWidgetModel.item = () => {};
      setValue(null);
    }
    setWidgetModel(newWidgetModel);
  };

  const WidgetComponent = ({ widgetModel }) => {
    const { title, id, type, color, borderColor, width, height, size, item} = widgetModel;
    if (type === 'rectangle') {
      return (
        <View
          style={{
            width: width,
            height: height,
            backgroundColor: '#ccccff',
            borderColor: '#e6e6ff',
            borderWidth: 2,
            borderRadius: 15,
          }}>
          {item()}
        </View>
      );
    } else if (type === 'middleRectangle') {
      return (
        <View
          style={{
            width: width,
            height: height,
            backgroundColor: '#ffccb3',
            borderColor: '#ffddcc',
            borderWidth: 2,
            borderRadius: 15,
          }}>
          {item()}
        </View>
      );
    } else if (type === 'square') {
      return (
        <View
          style={{
            width: size,
            height: size,
            backgroundColor: '#b3e0ff',
            borderColor: '#ccebff',
            borderWidth: 2,
            borderRadius: 15,
          }}>
          {item()}
        </View>
      );
    }
    else if (type === '') {
      return (
        <View
          style={{
            width: '95%',
            height: 200,
            backgroundColor: '#f2e6ff',
            borderColor: '#f2e6ff',
            borderWidth: 2,
            borderRadius: 15,
            justifyContent: 'center',
            alignItems: 'center',
          }}>
            <Text style={{fontSize: 16, color: '#8c8c8c'}}>Preview here</Text>
          </View>
      );
    }
  };


  const dataRectangle = [
    // { label: 'Currency Converter', value: '1', item: () => {return currencyWidget()}},
    { label: 'News', value: '1', item: () => {return newsWidget()}},
    { label: 'ChatGpt', value: '2', item: () => {return gptWidget()}},
    { label: 'Trombinoscope', value: '4', item: () => {return trombiWidget()} },
    { label: 'Map', value: '5', item: () => {return mapWidget()}},
  ];
  const dataMidRectangle = [
    { label: 'Weather', value: '6', item: () => {return weatherWidgetMiddle()}},
    { label: 'Events', value: '7', item: () => {return eventsWidget()}},
  ];
  const dataSquare = [
    { label: 'Weather', value: '10',  item: () => {return weatherWidgetSquare()} },
    { label: 'Trombinoscope', value: '11', item: () => {return trombiWidgetSquare()}},
    { label: 'Map', value: '12', item: () => {return mapWidget()}},
  ];

  let dataToUse;

  if (widgetModel.type === 'rectangle') {
    dataToUse = dataRectangle;
  } else if (widgetModel.type === 'middleRectangle') {
    dataToUse = dataMidRectangle;
  } else if (widgetModel.type === 'square') {
    dataToUse = dataSquare;
  } else {
    dataToUse = [{}];
  }

  const defaultWidget = {
    title: '',
    id: '',
    type: 'none',
    color: '',
    borderColor: '',
    width: '',
    height: '',
    size: '',
    item: () => {},
  };


  const handleAddElement = async (widgetModel) => {
    const lastElement = elements[elements.length - 1];
    if ((lastElement.type === 'rectangle' && widgetModel.type != 'square') || (lastElement.type === 'middleRectangle' && widgetModel.type != 'square')) {
      addWidget(widgetModel, defaultWidget);
      navigation.goBack();
      return;
    }
    else if ((lastElement.type === 'rectangle' && widgetModel.type === 'square') || (lastElement.type === 'middleRectangle' && widgetModel.type === 'square')) {
      addWidget(defaultWidget, widgetModel);
      navigation.goBack();
      return;
    }
    else if ((lastElement.type === 'square' && widgetModel.type === 'rectangle') || (lastElement.type === 'square' && widgetModel.type === 'middleRectangle')) {
      addWidget(defaultWidget, widgetModel);
      navigation.goBack();
      return;
    } else if ((lastElement.type === 'square' && widgetModel.type === 'square')) {
      addWidget(widgetModel, null);
      navigation.goBack();
      return;
    } else if ((lastElement.type === 'rectangle' && widgetModel.type === 'middleRectangle') && (lastElement.type === 'middleRectangle' && widgetModel.type === 'rectangle')) {
      addWidget(widgetModel, defaultWidget);
      navigation.goBack();
      return;
    }
    else if (lastElement.type === 'none') {
      if (widgetModel.type === 'rectangle' || widgetModel.type === 'middleRectangle') {
        addWidget(defaultWidget, widgetModel);
      } else if (widgetModel.type === 'square') {
        addWidget(widgetModel, null);
      }
      navigation.goBack();
      return;
    }
  };

  return (
    <SafeAreaView style={{ flex: 1, backgroundColor: '#fff'}}>
      <View style={styles.containerTitle}>
          <View style={styles.titleContainer}>
          <TouchableOpacity onPress={handleBackButtonPress}>
              <View style={{flex: 1, left: '30%', marginBottom: '80%'}}>
              <Icon style={{ color: "black", top: '70%' }} name="arrow-left" size={40} />
              </View>
          </TouchableOpacity>
          <Text style={{ fontSize: 40, fontWeight: 'bold', padding: '3%', paddingHorizontal: '15%', top:"3%"}}>
              Add Widget 📲
          </Text>
          <View style={{ flex: 1 }}></View>
          </View>
      </View>
      <ScrollView
      contentContainerStyle={{flex: 1, paddingBottom: '10%', marginBottom: '-40%'}}>
          <View style={styles.editScreen}>
            <View style={styles.sizeBox}>
              <Text style={styles.size}>Size</Text>
              <View style={styles.SizeContainer}>
                <TouchableOpacity
                  style={[
                    styles.rectangle,
                    selectedRectangles === 1 && { backgroundColor: '#e6e6ff', borderColor: '#ccccff', borderWidth: 2 },
                  ]}
                  onPress={() => handleRectangleClick(1)}>
                  <View style={[{height: '30%', height: '50%', backgroundColor: '#9999ff', borderRadius: 10,},
                  selectedRectangles === 1 && { backgroundColor: '#ccccff', borderColor: '#ccccff', borderWidth: 2 },]}/>
                </TouchableOpacity>

                <TouchableOpacity
                  style={[
                    styles.rectangle,
                    selectedRectangles  === 2 && { backgroundColor: '#e6e6ff', borderColor: '#ccccff', borderWidth: 2 },
                  ]}
                  onPress={() => handleRectangleClick(2)}>
                <View style={[{width: '100%', height: '30%', backgroundColor: '#9999ff', borderRadius: 10},
                selectedRectangles  === 2 && { backgroundColor: '#ccccff', borderColor: '#ccccff', borderWidth: 2 }]}/>
                </TouchableOpacity>

                <TouchableOpacity
                  style={[
                    styles.rectangle,
                    selectedRectangles  === 3 && { backgroundColor: '#e6e6ff', borderColor: '#ccccff', borderWidth: 2 },
                  ]}
                  onPress={() => handleRectangleClick(3)}>
                <View style={[{width: '55%', height: '35%', backgroundColor: '#9999ff', borderRadius: 10},
                 selectedRectangles  === 3 && { backgroundColor: '#ccccff', borderColor: '#ccccff', borderWidth: 2 }]}/>

              </TouchableOpacity>
            </View>
         </View>
          <View style={styles.sizeBox}>
            <Text style={styles.function}>Functionnality</Text>
            <Dropdown
              style={styles.dropdown}
              placeholderStyle={{color: '#bfbfbf'}}
              selectedTextStyle={styles.selectedTextStyle}
              inputSearchStyle={styles.inputSearchStyle}
              iconStyle={styles.iconStyle}
              data={dataToUse}
              maxHeight={'30%'}
              labelField="label"
              valueField="value"
              placeholder="Select a widget"
              value={value}
              onChange={item => {
                setValue(item.value);
                const newWidgetModel = { ...widgetModel };
                newWidgetModel.title = item.label;
                console.log(newWidgetModel.id);
                newWidgetModel.item = item.item;
                setWidgetModel(newWidgetModel);
              }}
            />
            <Text style={styles.function}>Inspector</Text>
            <View style={{alignItems: "center"}}>
              <WidgetComponent widgetModel={widgetModel}/>
            </View>
            <TouchableOpacity onPress={() => handleAddElement(widgetModel)} style={styles.addBtn}>
              <Text style={{fontWeight: 'bold', fontSize: 15, color: '#fff'}}>
                Add
              </Text>
            </TouchableOpacity>
          </View>
        </View>
      </ScrollView>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  convertButton: {
    backgroundColor: '#ffe6ff',
    padding: '2%',
    borderRadius: 10,
    marginLeft: 10,
  },
  pickerContainer: {
    borderRadius: 10,
    paddingHorizontal: 10,
    width: '25%',
    padding: '2%',
    backgroundColor: 'white',
  },
  addBtn: {
    width: "80%",
    height: '30%',
    borderRadius: 15,
    height: '20%',
    alignItems: "center",
    justifyContent: "center",
    marginTop: '10%',
    backgroundColor: "#cc99ff",
    alignSelf: 'center',
  },
  dropdown: {
    height: '20%',
    borderColor: 'black',
    borderWidth: 2,
    borderRadius: 8,
    paddingHorizontal: 8,
  },
  rectangle: {
    height: '100%',
    width: '30%',
    backgroundColor: "#ccccff",
    borderColor: "#9999ff",
    borderRadius: 15,
    borderWidth: 2,
    padding: 10,
  },
  rectangleText: {
    color: "black",
  },
  SizeContainer: {
    flex: 1,
    flexDirection: "row",
    justifyContent: 'space-between',
    backgroundColor: "#fff",
  },
  container: {
    flex: 1,
    flexDirection: "row"
  },
  icon2: {
    color: "rgba(128,128,128,1)",
    fontSize: 40,
    marginTop: 561
  },
  createWidgetScreen: {
    width: 371,
    height: 799,
    marginLeft: 124
  },
  appBar: {
    width: 318,
    height: 87,
    flexDirection: "row",
    justifyContent: "space-between",
    alignItems: "center"
  },
  icon: {
    color: "rgba(0,0,0,1)",
    fontSize: 80
  },
  addWidget: {
    color: "#121212",
    fontSize: 35
  },
  editScreen: {
    width: '95%',
    height: '120%',
    marginTop: '3%',
    alignItems: "center",
    backgroundColor: '#fff',
    alignSelf: 'center',
  },
  sizeBox: {
    width: '90%',
    height: '20%',
    backgroundColor: '#fff'
  },
  size: {
    color: "#121212",
    fontSize: 20,
    fontWeight: "bold",
    marginBottom: '10%',
  },
  function: {
    color: "#121212",
    fontSize: 20,
    fontWeight: "bold",
    marginBottom: '10%',
    marginTop: '8%',
    right: '1%'
  },
  group: {
    width: 60,
    height: 23
  },
  small: {
    color: "#121212",
    height: 23,
    width: 60,
    fontSize: 20
  },
  switch: {
    marginLeft: 11
  },
  large: {
    color: "#121212",
    height: 23,
    width: 73,
    fontSize: 20,
    marginLeft: 17
  },
  groupRow: {
    height: 23,
    flexDirection: "row",
    marginTop: 12,
  },
  contentBox: {
    width: 71,
    height: 24,
    marginTop: 48
  },
  content: {
    color: "#121212",
    fontSize: 20
  },
  cupertinoSearchBarBasic1: {
    height: 44,
    width: 212,
    borderRadius: 15,
    marginTop: 19
  },
  rect2: {
    width: 71,
    height: 24,
    marginTop: 99
  },
  color: {
    color: "#121212",
    fontSize: 20
  },
  cupertinoSearchBarBasic2: {
    height: 44,
    width: 212,
    borderRadius: 15,
    marginTop: 19
  },
  inspectorScreen: {
    width: 414,
    height: '10%',
    marginLeft: -32
  },
  inspecteur: {
    width: 414,
    height: 241,
    backgroundColor: "#E6E6E6"
  },
  inspector5: {
    color: "#121212",
    fontSize: 18,
    marginTop: 20,
    marginLeft: 159
  },
  rect: {
    width: 350,
    height: 149,
    backgroundColor: "rgba(214,127,231,1)",
    borderRadius: 15,
    marginTop: 17,
    marginLeft: 32
  },
  icon2Row: {
    height: 799,
    flexDirection: "row",
    flex: 1,
    marginRight: 11,
    marginLeft: -132,
    marginTop: 50
  },
    containerTitle: {
      backgroundColor: '#fff',
      height: '13%',
  },
  titleContainer: {
      paddingTop: '5%',
      flexDirection: 'row',
      justifyContent: 'center',
      paddingHorizontal: '3%',
  },
  container: {
      flex: 1,
      backgroundColor: '#fff',
      alignItems: 'center',
      justifyContent: 'center',
  },
  employeeImage: {
    width: '30%',
    height: '100%',
    borderRadius: 15,
  },
});

export default AddWidgetScreen;
