import axios from 'axios';
import React, { useState, useContext, Component } from 'react';
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
  Alert
} from 'react-native';
import { useEffect } from 'react';
import { useNavigation } from '@react-navigation/native';
import { Buffer } from 'buffer';
import Icon from 'react-native-vector-icons/MaterialCommunityIcons';
import { IconButton } from '@react-native-material/core';
import Icon2 from 'react-native-vector-icons/MaterialIcons';
import Icon3 from 'react-native-vector-icons/FontAwesome';
import { MyContext } from '../utils/Provider';
import EntypoIcon from "react-native-vector-icons/Entypo";
import Svg, { Ellipse } from "react-native-svg";
import MaterialCommunityIconsIcon from "react-native-vector-icons/MaterialCommunityIcons";
import FontAwesomeIcon from "react-native-vector-icons/FontAwesome";

const ProfileScreen = () => {
  const {data, setData} = useContext(MyContext);
  const [imageData, setImageData] = useState(null);
  const [Iuser, setIuser] = useState({});

  const navigation = useNavigation();
  const openDrawer = () => {
    navigation.navigate('Login');
  };

  return (
    <SafeAreaView style={{ flex: 1, backgroundColor: '#fff'}}>
      <View style={styles.containerTitle}>
        <View style={styles.titleContainer}>
          <Text style={{fontSize: 30, fontWeight: 'bold', padding: '3%', left: '18%', top: '0.5%'}}>Profile</Text>
          <IconButton disableRipple={true} style={{backgroundColor: 'transparent', position: 'absolute', right: '5%', top: '50%'
          }}
            icon={props => <Icon style={{color: "black"}} name="logout" size={30} />}
            onPress={openDrawer}
          />
        </View>
      </View>

      <View style={styles.container}>
        <View style={styles.infoBox}>
          {data.me.imageUrl && (
            <Image source={{ uri: data.me.imageUrl }} style={styles.image} />
          )}
          <Text style={{fontSize: 25, fontWeight: 'bold', padding: '6%', alignSelf: 'center', justifyContent: 'center'}}>{data.me.name + ' ' +  data.me.surname}</Text>
        </View>
      </View>

      {/* <View style={styles.container5}>
        <View style={styles.containerBtn}>
          <TouchableOpacity style={styles.button}>
            <Text style={styles.writeAMessage}>Write a message</Text>
          </TouchableOpacity>
          <TouchableOpacity style={styles.button4}>
            <Text style={styles.writeAMessage1}>Invite the participant</Text>
          </TouchableOpacity>
        </View>
      </View> */}

      <ScrollView contentContainerStyle={styles.containerScroll}>

      <View style={styles.container2}>
      <Text style={{fontSize: 40, fontWeight: 'bold', padding: '2%', paddingHorizontal: '10%', marginBottom: '3%'}}>Bio</Text>

      <View style={styles.infoContent}>
          <Text style={styles.infoText}>
            {data.me.bio}
          </Text>
        </View>


        <Text style={{fontSize: 40, fontWeight: 'bold', padding: '2%', paddingHorizontal: '10%', marginBottom: '3%'}}>About me</Text>

        <View style={styles.infoContent}>
          <Icon name="email" size={25} color="#000000" style={styles.icon} />
          <Text style={styles.infoText}>
            {data.me.email}
          </Text>
        </View>

        <View style={styles.infoContent}>
          {data.me.sexe === 'Male' ? (
            <Icon name="gender-male" size={25} color="#000000" style={styles.icon} />
          ) : (
            <Icon name="gender-female" size={20} color="#000000" style={styles.icon} />
          )}
          <Text style={styles.infoText}>
            {data.me.sexe}
          </Text>
        </View>

        <View style={styles.infoContent}>
          <Icon3 name="birthday-cake" size={23} color="#000000" style={styles.icon} />
          <Text style={styles.infoText}>
            {data.me.age}
          </Text>
        </View>

        <View style={styles.infoContent}>
          <Icon2 name="work" size={25} color="#000000" style={styles.icon} />
          <Text style={styles.infoText}>
            {data.me.fonction}
          </Text>
        </View>
      </View>
      </ScrollView>
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
    writeAMessage1: {
    color: "rgba(55,53,53,1)",
    textAlign: "center",
    alignItems: 'center',
    justifyContent: 'center',
  },
  writeAMessage: {
    color: "rgba(55,53,53,1)",
    textAlign: "center",
    alignItems: 'center',
    justifyContent: 'center',
  },
  containerTitle: {
    backgroundColor: '#fff',
    height: '13%',
  },
  button: {
    width: '55%',
    height: '130%',
    backgroundColor: "rgba(185,219,236,1)",
    borderRadius: 15,
    justifyContent: 'center',
    alignItems: 'center',
    right: '85%'
  },
  button4: {
    width: '55%',
    height: '130%',
    backgroundColor: "rgba(206,236,185,1)",
    borderRadius: 15,
    justifyContent: 'center',
    alignItems: 'center',
    left: '16%'
  },
  titleContainer: {
    paddingTop: '5%',
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'space-between',
    paddingHorizontal: '3%',
  },
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
    marginBottom: '3%',
  },
  container5: {
    top: '4%',
    flex: 0.4,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'space-between',
    marginBottom: '8%',
    paddingBottom: '3%',
  },

  containerScroll: {
    flexGrow: 1,
    backgroundColor: '#fff',
    top: '1%',
  },
  container2: {
    flex: 3,
    backgroundColor: '#fff',
  },
  image: {
    width: 70,
    height: 70,
    resizeMode: 'cover',
    borderRadius: 400,
    position: 'relative',
    padding: '1%',
    marginBottom: '1%',
  },
  containerBtn: {
    flexDirection: 'row',
    height: '82%',
    width: '90%',
    borderRadius: 20,
    position: 'absolute',
    marginBottom: '2%',
    marginTop: '2%',
    justifyContent: 'space-between',
    paddingHorizontal: '10%',
  },
  infoBox: {
    flexDirection: 'column',
    height: '82%',
    width: '90%',
    borderRadius: 20,
    position: 'absolute',
    marginBottom: '2%',
    marginTop: '2%',
    justifyContent: 'center',
    alignItems: 'center',
    paddingHorizontal: '10%',
  },
  infoContent: {
    flexDirection: 'row',
    alignItems: 'center',
    paddingTop: '1%',
    left: '15%',
  },
  infoTextTitle: {
    fontSize: 30,
    color: '#000000',
    marginTop: '6%',
    marginBottom: '2%',
    textAlign: 'center',
  },
  infoText: {
    fontSize: 15,
    color: '#000000',
    marginBottom: "2%",
    textAlign: 'center',
  },
  icon: {
    marginRight: '4%',
    marginBottom: '2.1%',
  },

});

export default ProfileScreen;
