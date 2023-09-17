import * as Animatable from 'react-native-animatable';
import React, { useState, useEffect, useContext } from 'react';
import { StyleSheet,
          TextInput,
          View,
          Image,
          Text,
          TouchableOpacity,
          ImageBackground,
          ScrollView,
          ActivityIndicator,
          FlatList,
          Button,
          Dimensions,
          SafeAreaView,
        } from 'react-native';
import { useNavigation } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import * as Location from 'expo-location';
import axios from 'axios';
import Icon from 'react-native-vector-icons/MaterialCommunityIcons';
import MapView, { Marker } from 'react-native-maps';
import RNPickerSelect from 'react-native-picker-select';
import { LinearGradient } from "expo-linear-gradient";
import { MyWidgetContext } from '../utils/WidgetProvider';




const Stack = createNativeStackNavigator();

// import { Drawer } from 'react-native-drawer-layout';
// import { Icon } from 'react-native-elements';
const widget = []

const isEven = (id) => {
  return id % 2 === 0;
};

const TabTop = () => {
  return (
    <View style={ styles.blackContainer}>
      <Icon name="more" size={30} color="black" />
    </View>
  );
}

// { id: '1', type: 'square', color: 'lightgrey', size: 170 },

// { id: '9', type: 'rectangle', color: 'lightgrey', width: '95%', height: 200 },

// { id: '8', type: 'rectangle', color: 'lightgrey', width: '95%', height: 100 },

const HomeScreen = () => {
  const navigation = useNavigation();
  const {elements, newElement} = useContext(MyWidgetContext);
  const { addWidget } = useContext(MyWidgetContext);

  const renderItem = ({ item }) => {
    if (item.type === 'square') {
      return (
        <TouchableOpacity
        style={[stylesWidgets.square, { backgroundColor: item.color, width: item.size, height: item.size, borderColor: item.borderColor, borderWidth: 2, backgroundColor: item.backgroundColor}]}>
          <View>
            {item.item()}
          </View>
        </TouchableOpacity>
      );
    } else if (item.type === 'rectangle') {
      return (
        <TouchableOpacity
        style={[stylesWidgets.rectangle, { backgroundColor: item.color, width: item.width, height: item.height, borderColor: item.borderColor, borderWidth: 2, backgroundColor: item.backgroundColor}]}>
          <View>
            {item.item()}
          </View>
        </TouchableOpacity>
      );
    } else if (item.type === 'middleRectangle') {
      return (
        <TouchableOpacity style={[stylesWidgets.rectangle, { backgroundColor: item.color, width: item.width, height: item.height, borderColor: item.borderColor, borderWidth: 2, backgroundColor: item.backgroundColor}]}>
          <View>
            {item.item()}
          </View>
        </TouchableOpacity>
      );
    }
  };

  const keyExtractor = (item) => item.id;

    return (
    <View style={stylesWidgets.container}>
      <FlatList
        showsVerticalScrollIndicator={false}
        data={elements}
        renderItem={renderItem}
        keyExtractor={keyExtractor}
        numColumns={2}
      />
    </View>
    // // <SafeAreaView style={{ width: Dimensions.get('window').width}}>
    // //   <ScrollView style={{flexDirection: 'column'}}
    // //   contentContainerStyle={{alignItems: 'center',paddingBottom: '30%', paddingTop: '2%'}}
    // //   showsVerticalScrollIndicator={false}>
    // //     <View style={{flexDirection: 'row', flexWrap: 'wrap', justifyContent: 'space-around'}}>
    //   {/* {widgets.map((item) => (
    //         <View key={item.id} style={item.large ? {
    //           borderRadius: 15,
    //           height: 230,
    //           marginHorizontal: 8,
    //           marginVertical: 10,
    //           width: '95%',
    //           backgroundColor: item.color,
    //         } : {
    //           borderRadius: 15,
    //           height: 180,
    //           width: '45%',
    //           margin: '2%',
    //           backgroundColor: item.color,
    //         }}>
    //           <item.item/>
    //     </View>
    //   ))} */}
    // //   </View>
    // //   </ScrollView>
    // // </SafeAreaView>
  );
};

const stylesWidgets = StyleSheet.create({
  container: {
    flex: 1,
    // justifyContent: 'center',
    // alignItems: 'center',
    paddingHorizontal: '2%'
  },
  square: {
    margin: 10,
    borderRadius: 15,
    borderColor: 'grey',
    borderWidth: 2,
  },
  rectangle: {
    margin: 10,
    borderRadius: 15,
    borderColor: 'grey',
    borderWidth: 2,
  },
});

const styles = StyleSheet.create({
  container3: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  colorBox: {
    marginVertical: 10,
  },
  buttonText: {
    fontSize: 16,
    fontWeight: 'bold',
    paddingHorizontal: '5%',
  },
  convertButton: {
    backgroundColor: '#ffe6ff',
    padding: '2%',
    borderRadius: 10,
    marginLeft: 10,
  },
  pickerContainer: {
    // borderWidth: 2,
    // borderColor: 'black',
    borderRadius: 10,
    // marginVertical: 10,
    paddingHorizontal: 10,
    width: '25%',
    padding: '2%',
    backgroundColor: 'white',
  },
  container: {
    flex: 1,
    backgroundColor: '#fff',
  },
  columnWrapper: {
    flexDirection: 'row',
    flexBasis: '100%',
  },
  smallItem: {
    // flex: 1,
    borderRadius: 15,
    height: 150,
    width: 150,
    backgroundColor: 'lightblue',
    margin: 8,
    alignItems: 'center',
    justifyContent: 'center',
  },
  largeItem: {
    // flex: 2,
    borderRadius: 15,
    height: 150,
    width: 300,
    // backgroundColor: item.color,
    margin: 8,
    alignItems: 'center',
    justifyContent: 'center',
  },
  textAppBar: {
    padding: '5%',
    fontSize: 20,
    fontWeight: 'bold',
    textDecorationLine: 'underline',
    color: 'lightgrey'
  },
  widgetsIcon: {
    flex: 1,
    textAlign: 'center',
    justifyContent: 'center',
    alignItems: 'center',
    fontSize: 50,
  },
  widgetsText: {
    flex: 1,
    textAlign: 'center',
    justifyContent: 'center',
    alignItems: 'center',
    fontSize: 20,
  },
  blackContainer: {
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: 'grey',
    borderRadius: 10,
    height: 20,
    width: 20,
    margin: 20,
  },
  scrollBar: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  }
});

export default HomeScreen;