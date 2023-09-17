import React, { createContext, useState, useContext } from 'react';
import {WidgetMap} from '../items/widgets/map';
// import { View } from 'react-native-animatable';
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
import { MyContext} from './Provider'
import filter from 'lodash.filter';

const MyWidgetContext = createContext();

const MyWidgetProvider = ({ children }) => {

  const [elements, setElements] = useState([]);

  const addWidget = async (newElement, emptyWidget) => {
    const updatedElements = [...elements, newElement];
    if (emptyWidget) {
      updatedElements.push(emptyWidget);
    }
    await setElements(updatedElements);
  };

  const setElem = async (newElements) => {
    await setElements(newElements);
  }

  return (
    <MyWidgetContext.Provider value={{ elements, addWidget, setElem }}>
      {children}
    </MyWidgetContext.Provider>
  );
};

export { MyWidgetProvider, MyWidgetContext };
