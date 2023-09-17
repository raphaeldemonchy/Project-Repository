import axios from 'axios';
import React, { useState, useCallback, useContext, forEach, useLayoutEffect } from 'react';
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
  Buttons
} from 'react-native';
import { useEffect } from 'react';
import { Buffer } from 'buffer';
import Icon from 'react-native-vector-icons/MaterialCommunityIcons';
import { Button, IconButton } from '@react-native-material/core';
import Icon2 from 'react-native-vector-icons/MaterialIcons';
import Icon3 from 'react-native-vector-icons/FontAwesome';
import { useNavigation } from '@react-navigation/native';
import { AppRegistry } from 'react-native';
import { GiftedChat, Send, Bubble } from 'react-native-gifted-chat'
import io from 'socket.io-client';
import { MyContext } from '../utils/Provider';
let fo = false;

const ChatScreen = ({ route }) => {
  const {employeeInfo, idConversation, messages} = route.params;
  const [newMessages, setNewMessages] = useState([]);
  const {data, setData} = useContext(MyContext);
  const navigation = useNavigation();
  const socket = io('http://10.79.216.104:3000/');
  let count = 0;
  const iu = ['tfdtyg'];
  let idSocket = null;
    useEffect(() => {
      socket.emit('join', idConversation);
      socket.on('set id', (data) => {
        if (idSocket == null)
        idSocket = data;
      });
      const messagesTransformes = messages.map((message) => {
        console.log(message);
        return {
          _id: message.id,
          text: message.text,
          createdAt: new Date(message.createdAt),
          user: {
            _id: message._id,
            name: message.name,
            avatar: 'none',
          },
        };
      });
      messagesTransformes.reverse();
      // setNewMessages((previousMessages) => GiftedChat.append(previousMessages, messagesTransformes));
      socket.on('message received', async (message) => {
        const uniqueId = new Date().getTime() + count;
        count = count + 1;
        let formattedMessage = {
          _id: uniqueId,
          text: message.text,
          createdAt: new Date(message.createdAt),
          user: {
            name: employeeInfo.name + ' ' + employeeInfo.surname,
            _id: 2,
          },
        };
        if (message.id !== idSocket)
            setNewMessages((previousMessages) => GiftedChat.append(previousMessages, [formattedMessage]));
      });
    }, []);

    const handleBackButtonPress = () => {
      navigation.goBack();
      socket.emit('leave', idConversation);
    };


    const onSend = useCallback((myMessages = []) => {
      const dateTime = new Date();
      const uniqueId = new Date().getTime() + count;
      count++;
      myMessages[0].idConversation = idConversation;
      myMessages[0].id = idSocket;
      myMessages[0].idSender = data.me.id;
      myMessages[0].date = dateTime.toString();
      let formattedMessage = {
        _id: uniqueId,
        text: myMessages[0].text,
        createdAt: new Date(myMessages[0].date),
        user: {
          name: data.me.name + ' ' + data.me.surname,
          _id: data.me.id,
        },
      };
      setNewMessages((previousMessages) => GiftedChat.append(previousMessages, myMessages),)
      socket.emit('message', myMessages[0]);
    }, [])

    // const renderBubble = (myMessages) => {
    //   const backgroundColor = myMessages.user._id === data.me.id ? 'blue' : 'green';
    //   return (
    //     <View style={{ backgroundColor }}>
    //       <Text>{myMessages.text}</Text>
    //     </View>
    //   );
    // };
    const placeHolder = `Type a message to ${employeeInfo.name} 😉...`
    return (
      <SafeAreaView style={{ flex: 1, backgroundColor: '#fff'}}>
        <View style={styles.containerTitle}>
            <View style={styles.titleContainer}>
            <TouchableOpacity onPress={handleBackButtonPress}>
                <View style={styles.backButton}>
                <Icon style={{ color: "black", top: '65%' }} name="arrow-left" size={40} />
                </View>
            </TouchableOpacity>
            <Text style={{ fontSize: 20, fontWeight: 'bold', padding: '3%', paddingHorizontal: '10%', top: '6%', alignSelf: 'center' }}>
                {employeeInfo.name + ' ' + employeeInfo.surname}
            </Text>
            <View style={{ flex: 1 }}></View>
            </View>
        </View>
        <GiftedChat
          messages={newMessages}
          onSend={m => onSend(m)}
          user={{
            _id: data.me.id,
          }}
          placeholder={placeHolder}
          // renderBubble={renderBubble}
        />
    </SafeAreaView>
    );
}

const styles = StyleSheet.create({
  test: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    width: '100%',
    height: '100%',
  },
	containera: {
    flexDirection: 'row',
    alignItems: 'center',
    paddingHorizontal: 16,
    paddingVertical: 8,
    backgroundColor: 'white',
    borderTopWidth: 1,
    borderTopColor: '#ccc',
  },
	iconContainer: {
    paddingHorizontal: 8,
  },
  textInput: {
    flex: 1,
    fontSize: 16,
    paddingVertical: 8,
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
  containerChat: {
    flex: 1,
    backgroundColor: '#fff',
		alignItems: 'center',
		width: '90%',
  },
  container2: {
    flex: 3,
    backgroundColor: '#fff',
  },
  image: {
    width: '29%',
    height: '70%',
    resizeMode: 'cover',
    borderRadius: 180,
    position: 'relative',
    padding: '1%',
    left: '1%',
  },
  infoBox: {
    backgroundColor: '#ffb3b3',
    flexDirection: 'row',
    height: '82%',
    width: '90%',
    borderRadius: 20,
    position: 'absolute',
    marginBottom: '2%',
    marginTop: '2%',
    justifyContent: 'space-between',
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

export default ChatScreen;