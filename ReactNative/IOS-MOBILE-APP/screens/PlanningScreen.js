import React, { useState } from 'react';
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
  ActivityIndicator
} from 'react-native';
import DatePicker from 'react-native-modern-datepicker';
import Swiper from 'react-native-swiper';
import DateTimePicker from '@react-native-community/datetimepicker';
import CalendarComponent from '../components/Calendar';
import HeaderCalandar from '../components/HeaderCalandar';

const PlanningScreen = () => {
  const [selectedDate, setSelectedDate] = useState('');
  const [currentMonth, setCurrentMonth] = useState(new Date());
  const [selectedTime, setSelectedTime] = useState(null);
  const [showTimePicker, setShowTimePicker] = useState(false);

  const handleDateChange = (date) => {
    setSelectedDate(date);
  };

  const handleMonthChange = (index) => {
    const newMonth = new Date(currentMonth);
    newMonth.setMonth(currentMonth.getMonth() + index);
    setCurrentMonth(newMonth);
  };

  const handleTimeChange = (event, time) => {
    if (Platform.OS === 'android') {
      setShowTimePicker(false);
    }
    if (time !== undefined) {
      setSelectedTime(time.toLocaleTimeString());
    }
  };

  const showTimePickerModal = () => {
    setShowTimePicker(true);
  };

  return (
    <SafeAreaView style={{ flex: 1, backgroundColor: '#fff'}}>
      <View style={styles.container}>
        <Text style={{fontSize: 40, fontWeight: 'bold', padding: '7%'}}>Planning 📅</Text>
      </View>
      <View style={{ flex: 1 }}>
        <CalendarComponent/>
      </View>
    </SafeAreaView>
  );
};

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
      backgroundColor: '#e1d0fc',
      borderRadius: 20,
      marginBottom: 16,
      width: '90%',
      alignItems: 'center',
      flexDirection: 'row',
    },
    employeeInfo: {
      flex: 1,
    },
    employeeImage: {
      width: '12%',
      height: '85%',
      borderRadius: 50,
      marginLeft: 5,
    },
});

export default PlanningScreen;
