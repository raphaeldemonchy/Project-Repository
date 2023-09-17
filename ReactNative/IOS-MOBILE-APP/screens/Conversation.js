import axios from 'axios';
import React, { useState, forEach, useContext } from 'react';
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
} from 'react-native';
import { useEffect } from 'react';
import { Buffer } from 'buffer';
import Icon from 'react-native-vector-icons/MaterialCommunityIcons';
import { IconButton } from '@react-native-material/core';
import Icon2 from 'react-native-vector-icons/MaterialIcons';
import Icon3 from 'react-native-vector-icons/FontAwesome';
import { useNavigation } from '@react-navigation/native';
import { MyContext } from '../utils/Provider';

const Conversation = () => {
    const {data, setData} = useContext(MyContext);
    // const [conversationsData, setConversationsData] = useState([])
    const navigation = useNavigation();
    const handleBackButtonPress = () => {
        navigation.goBack();
    };
    const [messages, setMessages] = useState([]);

    const getConversation = async (idConversation) => {
      const tab = [];
      await axios.get(`http://10.79.216.104:1234/conversations/${idConversation}`).then((conversation) => {
      // console.log('CONV: ' + conversation.data)
      conversation.data.messages.forEach(element => {
          let message = {
            _id: element.idSender,
            text: element.text,
            createdAt: element.date,
            user: {
              name: element.name,
              _id: element.idSender,
            },
          };
          tab.push(message);
        });
      });
      return (tab);
  }

    const onItemClick = async (employeeInfo, idConversation) => {
      const newMsg = await getConversation(idConversation);
      const item = {
        employeeInfo: employeeInfo,
        idConversation: idConversation,
        messages: newMsg
      }
      navigation.navigate('ChatScreen', item);
    };

    return (
      <SafeAreaView style={{ flex: 1, backgroundColor: '#fff'}}>
            <View style={styles.containerTitle}>
                <View style={styles.titleContainer}>
                <TouchableOpacity onPress={handleBackButtonPress}>
                  <View style={styles.backButton}>
                    <Icon style={{ color: "black", top: '60%', left: '45%' }} name="arrow-left" size={40} />
                  </View>
                </TouchableOpacity>
                <Text style={{ fontSize: 40, fontWeight: 'bold', padding: '3%', paddingHorizontal: '15%', top:"2%"}}>
                    Conversation
                </Text>
                <View style={{ flex: 1 }}></View>
                </View>
            </View>
            <ScrollView contentContainerStyle={styles.container2}>
                  {data.conversations.map((conv, index) => {
                    let newEmployee = conv.guests.find((guest) => {
                       return (guest.id !== data.me.id);
                    });
                    let convEmployee = data.employee.find((employee) => {
                      return (employee.id == newEmployee.id);
                    });
                    return (
                    conv.isGroup ?
                    <TouchableOpacity
                      style={styles.employeeContainer}
                      key={index}
                      // onPress={() => onItemClick(meConv)}
                    >
                    <View style={styles.employeeInfo}>
                      <Text style={{fontWeight: 'bold'}}>GROUP</Text>
                      <Text style={{fontWeight: conv.isSeen ? null : 'bold'}}>{conv.lastMessage}</Text>
                    </View>
                  </TouchableOpacity>
                    : <TouchableOpacity
                      style={styles.employeeContainer}
                      onPress={() => {
                        onItemClick(convEmployee, conv._id)
                      }}
                      key={index}
                    >
                    <View style={styles.employeeInfo}>
                      <Text style={{fontWeight: 'bold'}}>{convEmployee.name + ' ' + convEmployee.surname}</Text>
                      <Text style={{fontWeight:conv.isSeen ? null : 'bold'}}>{conv.lastMessage}</Text>
                      <Text>{conv.fonction}</Text>
                    </View>
                  </TouchableOpacity>
                  );})}
                </ScrollView>
        </SafeAreaView>
    );
}

const styles = StyleSheet.create({
    container: {
        backgroundColor: '#fff',
        height: '15%',
    },
    container2: {
        flexGrow: 1,
        backgroundColor: '#fff',
        alignItems: 'center',
        paddingTop: '7%',
    },
    employeeContainer: {
        padding: '3%',
        backgroundColor: '#D4E3E1',
        borderRadius: 20,
        marginBottom: 16,
        width: '90%',
        alignItems: 'center',
        flexDirection: 'row',
      },
    employeeInfo: {
    flex: 1,
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
})

export default Conversation;