import React, { useState } from 'react';
import { View, Text, TouchableOpacity, Platform, FlatList, StyleSheet, Button, TextInput, Image, Modal } from 'react-native';
import DatePicker from 'react-native-modern-datepicker';
import DateTimePickerModal from 'react-native-modal-datetime-picker';
import {Calendar, CalendarList, Agenda, LocaleConfig} from 'react-native-calendars';
import moment from 'moment';
import axios from "axios";


LocaleConfig.locales['fr'] = {
  monthNames: [
    'Janvier',
    'Février',
    'Mars',
    'Avril',
    'Mai',
    'Juin',
    'Juillet',
    'Août',
    'Septembre',
    'Octobre',
    'Novembre',
    'Décembre'
  ],
  monthNames: [
    'Janvier',
    'Février',
    'Mars',
    'Avril',
    'Mai',
    'Juin',
    'Juillet',
    'Août',
    'Septembre',
    'Octobre',
    'Novembre',
    'Décembre'
  ],
  monthNamesShort: ['Janv.', 'Févr.', 'Mars', 'Avril', 'Mai', 'Juin', 'Juil.', 'Août', 'Sept.', 'Oct.', 'Nov.', 'Déc.'],
  dayNames: ['Dimanche', 'Lundi', 'Mardi', 'Mercredi', 'Jeudi', 'Vendredi', 'Samedi'],
  dayNamesShort: ['S', 'M', 'T', 'W', 'T', 'F', 'S'],
  today: "Aujourd'hui"
};

LocaleConfig.defaultLocale = 'fr';


const CalendarComponent = () => {
  

            // NEW CALANDAR

    const [markedDates, setMarkedDates] = useState({
    '2021-01-20': {textColor: 'green'},
    '2021-01-22': {startingDay: true, color: 'green'},
    '2021-01-23': {selected: true, endingDay: true, color: 'green', textColor: 'gray'},
    '2021-01-04': {disabled: true, startingDay: true, color: 'green', endingDay: true}
  })

  const handleDayPress = (day) => {
    setMarkedDates({
      [day.dateString]: {
        startingDay: true,color: '#ccccff'
      },
      [moment(day.dateString).add(1, 'days').format('YYYY-MM-DD')]: {
        color: '#ccccff'
      },
      [moment(day.dateString).add(2, 'days').format('YYYY-MM-DD')]: {
        color: '#ccccff'
      },
      [moment(day.dateString).add(3, 'days').format('YYYY-MM-DD')]: {
        endingDay: true,color: '#ccccff'
      }
    })
  }

  const handlePressAdd = () => {

  };
  
  const openModal = () => {
    setModalVisible(true);
  };

  const closeModal = () => {
    setModalVisible(false);
  };

  const saveAndCloseModal = () => {
    const body =
    {
      title: title,
      description: description,
      date: date,
      object: object,
      organizer: {id: 1, surname: 'moi', name: 'moi'},
      guests: [{id: 2, surname: 'eux', name: 'eux'}]
    }
    axios.post('http://10.79.216.104:1234/events', body);
    closeModal();
  };

  const [title, setTitle] = useState("");
  const [description, setDescription] = useState("");
  const [date, setDate] = useState("");
  const [object, setObject] = useState("");
  const [guests, setGuests] = useState([{}]);


  const [modalVisible, setModalVisible] = useState(false);

                // POP UP 1   selectedDate

  const [isDatePickerVisible, setDatePickerVisibility] = useState(false);
  const [selectedDate, setSelectedDate] = useState(null);

  const showDatePicker = () => {
    setDatePickerVisibility(true);
  };

  const hideDatePicker = () => {
    setDatePickerVisibility(false);
  };

  const handleConfirm = (date) => {
    setSelectedDate(date);
    hideDatePicker();
  }
  // // // // // // //

  const [isTimePickerVisible, setTimePickerVisibility] = useState(false);
  const [selectedTime, setSelectedTime] = useState(null);

  const showTimePicker = () => {
    setTimePickerVisibility(true);
  };

  const hideTimePicker = () => {
    setTimePickerVisibility(false);
  };

  const handleTimeConfirm = (time) => {
    setSelectedTime(time);
    hideTimePicker();
  };

              // POP UP 2    selectedDate2
  const [isDatePickerVisible2, setDatePickerVisibility2] = useState(false);
  const [selectedDate2, setSelectedDate2] = useState(null);

  const showDatePicker2 = () => {
    setDatePickerVisibility(true);
  };

  const hideDatePicker2 = () => {
    setDatePickerVisibility(false);
  };

  const handleConfirm2 = (date) => {
    setSelectedDate(date);
    hideDatePicker();
  }

  // // // // // // //
  const [isTimePickerVisible2, setTimePickerVisibility2] = useState(false);
  const [selectedTime2, setSelectedTime2] = useState(null);

  const showTimePicker2 = () => {
    setTimePickerVisibility(true);
  };

  const hideTimePicker2 = () => {
    setTimePickerVisibility(false);
  };

  const handleTimeConfirm2 = (time) => {
    setSelectedTime(time);
    hideTimePicker();
  };

  return (
    <View style={{ flex: 1 }}>
      <View style={{ flex: 1, justifyContent: 'top', alignItems: 'center' }}>
        {/* <DatePicker
          mode="calendar"
          onDateChange={handleDateChange}
          date={currentMonth}
          style={{ width: 300, backgroundColor: 'white', color: 'red' }}
        /> */}
        <CalendarList
          onVisibleMonthsChange={(months) => {console.log('now these months are visible', months);}}
          pastScrollRange={50}
          futureScrollRange={50}
          markedDates={markedDates}
          markingType={'period'}
          onDayPress={handleDayPress}
          scrollEnabled={true}
          // Enable or disable the vertical scroll indicator. Default = false
          showScrollIndicator={true}
          // dayFormat={'S'}
          theme={{
            backgroundColor: 'red',
            calendarBackground: '#fff',
            textSectionTitleColor: '#000099',
            selectedDayBackgroundColor: '#8080ff',
            selectedDayTextColor: ' #fff',
            todayTextColor: '#ff66cc',
            dayTextColor: '#000099',
            monthTextColor: '#000000',
            textDisabledColor: '#d9e'
          }}
        />

      </View>
      <TouchableOpacity onPress={openModal}>
        <View style={styles.bottomRightContainer}>
          <Image
            source={require('../assets/plus.png')} // Remplacez par le chemin de votre image
            style={styles.image}
          />
        </View>
      </TouchableOpacity>

      <Modal animationType="slide" visible={modalVisible} onRequestClose={closeModal}>
        <View style={{height: '100%', width: '100%', backgroundColor: '#fff'}}>
          <View style={styles.header}>

            <TouchableOpacity onPress={saveAndCloseModal} style={styles.closeButton}>
              <View style={styles.quitHeader}>
                <Image
                  source={require('../assets/bouton-x.png')}
                  style={{height: 15, width: 15}}
                />
              </View>
            </TouchableOpacity>

            <TextInput onChangeText={setTitle} defaultValue="Name event..." style={styles.headerText}></TextInput>

            <TouchableOpacity onPress={saveAndCloseModal} style={styles.saveButton}>
              <View style={styles.saveHeader}>
                <Text style={styles.saveText}>Save</Text>
              </View>
            </TouchableOpacity>

          </View>

          <View style={styles.popContainer}>
            <Text style={{color: 'black', marginLeft:10, fontSize: 15}}>From</Text>

          <TouchableOpacity onPress={showDatePicker}>
            <View style={{borderColor:'#ccccff', borderWidth: 1, height: 50, width: 220, backgroundColor: '#fff', marginLeft:10, borderRadius: 5, shadowColor: '#ccccff', shadowOffset: { width: 0, height: 2 }, shadowOpacity: 0.5, shadowRadius: 5}}>
              <View style={{marginLeft: 190, marginTop: 15}}>
                <Image
                  source={require('../assets/arrow.png')}
                  style={{height: 15, width: 15}}
                />
              </View>
            </View>

              <DateTimePickerModal
                isVisible={isDatePickerVisible}
                mode="date"
                onConfirm={handleConfirm}
                onCancel={hideDatePicker}
                textColor='black'
            />

          </TouchableOpacity>

          <TouchableOpacity onPress={showTimePicker} >
            <View style={{borderColor:'#ccccff', borderWidth: 1, height: 50, width: 170, backgroundColor: '#f0f0ff', marginLeft:235, borderRadius: 5, top: -50, shadowColor: '#ccccff', shadowOffset: { width: 0, height: 1 }, shadowOpacity: 0.5, shadowRadius: 5}}>
              <View style={{marginLeft: 140, marginTop: 15}}>
                <Image
                  source={require('../assets/arrow.png')}
                  style={{height: 15, width: 15}}
                />
              </View>
            </View>
            <DateTimePickerModal
              isVisible={isTimePickerVisible}
              mode="time"
              onConfirm={handleTimeConfirm}
              onCancel={hideTimePicker}
              textColor="black"
            />
          </TouchableOpacity>


            <Text style={{color: 'black', marginLeft:10, fontSize: 15}}>To</Text>

          <TouchableOpacity onPress={showDatePicker2}>
            <View style={{borderColor:'#ccccff', borderWidth: 1, height: 50, width: 220, backgroundColor: '#f0f0ff', marginLeft:10, borderRadius: 5, shadowColor: '#ccccff', shadowOffset: { width: 0, height: 2 }, shadowOpacity: 0.5, shadowRadius: 5}}>
              <View style={{marginLeft: 190, marginTop: 15}}>
                <Image
                  source={require('../assets/arrow.png')}
                  style={{height: 15, width: 15}}
                />
              </View>
            </View>

            <DateTimePickerModal
                isVisible={isDatePickerVisible}
                mode="date"
                onConfirm={handleConfirm2}
                onCancel={hideDatePicker2}
                textColor='black'
            />

          </TouchableOpacity>

          <TouchableOpacity onPress={showTimePicker2}>
            <View style={{borderColor:'#ccccff', borderWidth: 1, height: 50, width: 170, backgroundColor: '#f0f0ff', marginLeft:235, borderRadius: 5, top: -50, shadowColor: '#ccccff', shadowOffset: { width: 0, height: 2 }, shadowOpacity: 0.5, shadowRadius: 5}}>
              <View style={{marginLeft: 140, marginTop: 15}}>
                <Image
                  source={require('../assets/arrow.png')}
                  style={{height: 15, width: 15}}
                />
              </View>
            </View>
            <DateTimePickerModal
              isVisible={isTimePickerVisible}
              mode="time"
              onConfirm={handleTimeConfirm}
              onCancel={hideTimePicker}
              textColor="black"
            />
          </TouchableOpacity>
          </View>

          <View style={styles.popContainer2}>

          </View>

        </View>
      </Modal>

    </View>
  );
};

const styles = StyleSheet.create({
  bottomRightContainer: {
    position: 'absolute',
    bottom: 0,
    right: 0,
    height: 100,
    width: 100,
    margin: 20,
    backgroundColor: 'rgba(73, 65, 109, 0.8)',
    borderRadius: 30,
    alignItems: 'center',
  },

  detailInput: {
    backgroundColor: 'white',
    borderColor: '#black',
    borderRadius: 30
  },

  saveText: {
    color: '#665687'
  },

  headerText: {
    fontSize: 22,
    width: 200,
    top: 20,
    left: '15%',
    color: '#E4E3E4',
    backgroundColor: 'transparent'
  },

  popContainer: {
    top: 50,
    backgroundColor: '#fff',
    height: 300,
    width: '100%',
    marginTop: 100,
  },

  popContainer2: {
    backgroundColor: '#fff',
    height: 300,
    width: '100%',
    marginTop: 10,
  },


  closeText: {
    color: 'white'
  },

  header: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    alignItems: 'center',
    backgroundColor: '#b3b3ff',
    paddingHorizontal: 16,
    paddingVertical: 0,
    width: '100%',
    height: 100,
    position: 'absolute',
    zIndex: 1,
  },

  saveHeader: {
    backgroundColor: 'transparent',
    top: 20,
    marginLeft: 80,
    padding: 15,
    height: 50,
    width: 80,
  },

  quitHeader: {
    top: 20,
    backgroundColor: 'transparent',
    padding: 12,
    height: 40,
    width: 40,
  },

  image: {
    width: 10, // Ajustez la largeur et la hauteur selon vos besoins
    height: 10,
    padding: 15,
    marginTop: 33,
  },

  content: {
    top :"10%"
  },

  eventNameInput: {
    height: 30,
    width: 100,
    borderColor: 'black',
    borderWidth: 1,
    borderRadius: 5,
    marginTop: -20,
    paddingHorizontal: 10,
  },

  part1: {
    alignItems: 'center',
    top: 2,
    height: 40,
    width: '100%',
    borderBottomEndRadius: 10,
    borderBottomStartRadius: 10,
    backgroundColor: 'lightgrey',
  },

  containerButton: {
    height: 40,
    width: '100%',
    padding: 10,
    alignItems: 'center',
    borderRadius: 10,
    backgroundColor: 'lightgrey',
    top: 10,
    shadowColor: 'grey',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.2,
    shadowRadius: 3,
  },

  containerButtonClicked: {
    backgroundColor: 'lightgrey',
    borderBlockColor: 'white',
    borderWidth: 1,
  },

  containerButtonProject: {
    height: 40,
    width: '100%',
    padding: 10,
    alignItems: 'center',
    borderRadius: 10,
    backgroundColor: 'lightgrey',
    top: 15,
    shadowColor: 'grey',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.2,
    shadowRadius: 3,
  },

  container2: {
    marginTop: 5,
    height: 100,
    width: '100%',
    padding: 10,
    top: 5,
    alignItems: 'center',
    backgroundColor: 'lightgrey',
    borderBottomRightRadius: 10,
    borderBottomLeftRadius: 10,
    shadowColor: 'grey',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.2,
    shadowRadius: 3,
  },

  container3: {
    marginTop: 5,
    height: 100,
    width: '100%',
    padding: 10,
    top: 5,
    alignItems: 'center',
    backgroundColor: 'lightgrey',
    borderBottomRightRadius: 10,
    borderBottomLeftRadius: 10,
    shadowColor: 'grey',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.2,
    shadowRadius: 3,
  },

  selectedTime: {
    fontWeight: 'bold',
    fontSize: 14,
    marginTop: 10,
    color: 'black',
  },

  buttonText: {
    fontWeight: 'bold',
    fontSize: 14,
  },

  timePicker: {
    height: '100%',
    width: '100%',
  },
});

export default CalendarComponent;
