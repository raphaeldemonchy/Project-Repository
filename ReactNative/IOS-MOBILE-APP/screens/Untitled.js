import React, { Component } from "react";
import { StyleSheet, View, TouchableOpacity, Text } from "react-native";
import EntypoIcon from "react-native-vector-icons/Entypo";
import Svg, { Ellipse } from "react-native-svg";
import MaterialCommunityIconsIcon from "react-native-vector-icons/MaterialCommunityIcons";
import FontAwesomeIcon from "react-native-vector-icons/FontAwesome";

function ProfileScreen(props) {
  return (
    <View style={styles.container}>
      <View style={styles.button2Row}>
        <TouchableOpacity style={styles.button2}>
          <View style={styles.icon5Row}>
            <EntypoIcon name="chevron-left" style={styles.icon5}></EntypoIcon>
            <Text style={styles.profile}>Profile</Text>
          </View>
        </TouchableOpacity>
        <Svg viewBox="0 0 87.59 77.43" style={styles.ellipse}>
          <Ellipse
            stroke="rgba(230, 230, 230,1)"
            strokeWidth={0}
            fill="rgba(230, 230, 230,1)"
            cx={44}
            cy={39}
            rx={44}
            ry={39}
          ></Ellipse>
        </Svg>
        <TouchableOpacity style={styles.button3}>
          <EntypoIcon name="log-out" style={styles.icon6}></EntypoIcon>
        </TouchableOpacity>
      </View>
      <View style={styles.buttonRow}>
        <TouchableOpacity style={styles.button}>
          <Text style={styles.writeAMessage}>Write a message</Text>
        </TouchableOpacity>
        <TouchableOpacity style={styles.button4}>
          <Text style={styles.writeAMessage1}>Invite the participant</Text>
        </TouchableOpacity>
      </View>
      <Text style={styles.name}>Name</Text>
      <Text style={styles.bio}>Bio</Text>
      <Text style={styles.squeJaiADire}>sque jai a dire</Text>
      <Text style={styles.aboutMe}>About me</Text>
      <View style={styles.iconRow}>
        <EntypoIcon name="mail" style={styles.icon}></EntypoIcon>
        <Text style={styles.loremIpsum}>Lorem Ipsum</Text>
      </View>
      <View style={styles.icon2Row}>
        <MaterialCommunityIconsIcon
          name="gender-male"
          style={styles.icon2}
        ></MaterialCommunityIconsIcon>
        <Text style={styles.loremIpsum1}>Lorem Ipsum</Text>
      </View>
      <View style={styles.icon3Row}>
        <FontAwesomeIcon
          name="birthday-cake"
          style={styles.icon3}
        ></FontAwesomeIcon>
        <Text style={styles.loremIpsum2}>Lorem Ipsum</Text>
      </View>
      <View style={styles.icon4Row}>
        <FontAwesomeIcon name="suitcase" style={styles.icon4}></FontAwesomeIcon>
        <Text style={styles.loremIpsum3}>Lorem Ipsum</Text>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1
  },
  button2: {
    width: 122,
    height: 31,
    backgroundColor: "rgba(230,230, 230,0)",
    flexDirection: "row"
  },
  icon5: {
    color: "rgba(0,0,0,1)",
    fontSize: 34
  },
  profile: {
    fontFamily: "roboto-700",
    color: "#121212",
    fontSize: 23,
    width: 84,
    height: 33,
    marginLeft: 4,
    marginTop: 4
  },
  icon5Row: {
    height: 37,
    flexDirection: "row",
    flex: 1
  },
  ellipse: {
    width: 88,
    height: 77,
    marginLeft: 16,
    marginTop: 27
  },
  button3: {
    width: 38,
    height: 35,
    backgroundColor: "#E6E6E6",
    opacity: 0,
    marginLeft: 70,
    marginTop: 1
  },
  icon6: {
    color: "rgba(0,0,0,1)",
    fontSize: 23,
    height: 25,
    width: 23,
    marginTop: 5,
    marginLeft: 11
  },
  button2Row: {
    height: 104,
    flexDirection: "row",
    marginTop: 57,
    marginLeft: 11,
    marginRight: 30
  },
  button: {
    width: 159,
    height: 29,
    backgroundColor: "rgba(185,219,236,1)",
    borderRadius: 15
  },
  writeAMessage: {
    fontFamily: "roboto-regular",
    color: "rgba(55,53,53,1)",
    fontSize: 12,
    width: 118,
    height: 16,
    textAlign: "center",
    marginTop: 6,
    marginLeft: 23
  },
  button4: {
    width: 159,
    height: 29,
    backgroundColor: "rgba(206,236,185,1)",
    borderRadius: 15,
    marginLeft: 25
  },
  writeAMessage1: {
    fontFamily: "roboto-regular",
    color: "rgba(55,53,53,1)",
    fontSize: 12,
    width: 118,
    height: 16,
    textAlign: "center",
    marginTop: 6,
    marginLeft: 20
  },
  buttonRow: {
    height: 29,
    flexDirection: "row",
    marginTop: 74,
    marginLeft: 19,
    marginRight: 13
  },
  name: {
    fontFamily: "roboto-700",
    color: "#121212",
    width: 180,
    height: 20,
    fontSize: 19,
    textAlign: "center",
    marginTop: -87,
    marginLeft: 103
  },
  bio: {
    fontFamily: "roboto-700",
    color: "#121212",
    fontSize: 27,
    width: 58,
    height: 39,
    marginTop: 115,
    marginLeft: 22
  },
  squeJaiADire: {
    fontFamily: "roboto-regular",
    color: "rgba(12,5,5,1)",
    height: 152,
    width: 314,
    marginTop: 1,
    marginLeft: 27
  },
  aboutMe: {
    fontFamily: "roboto-700",
    color: "#121212",
    fontSize: 27,
    width: 175,
    height: 46,
    marginTop: 20,
    marginLeft: 22
  },
  icon: {
    color: "rgba(0,0,0,1)",
    fontSize: 23
  },
  loremIpsum: {
    fontFamily: "roboto-regular",
    color: "#121212",
    width: 223,
    height: 20,
    marginLeft: 41,
    marginTop: 4
  },
  iconRow: {
    height: 25,
    flexDirection: "row",
    marginTop: 18,
    marginLeft: 32,
    marginRight: 56
  },
  icon2: {
    color: "rgba(0,0,0,1)",
    fontSize: 25
  },
  loremIpsum1: {
    fontFamily: "roboto-regular",
    color: "#121212",
    width: 223,
    height: 16,
    marginLeft: 42,
    marginTop: 6
  },
  icon2Row: {
    height: 27,
    flexDirection: "row",
    marginTop: 19,
    marginLeft: 29,
    marginRight: 56
  },
  icon3: {
    color: "rgba(0,0,0,1)",
    fontSize: 24
  },
  loremIpsum2: {
    fontFamily: "roboto-regular",
    color: "#121212",
    width: 208,
    height: 16,
    marginLeft: 42,
    marginTop: 8
  },
  icon3Row: {
    height: 24,
    flexDirection: "row",
    marginTop: 22,
    marginLeft: 30,
    marginRight: 71
  },
  icon4: {
    color: "rgba(0,0,0,1)",
    fontSize: 24
  },
  loremIpsum3: {
    fontFamily: "roboto-regular",
    color: "#121212",
    width: 208,
    height: 20,
    marginLeft: 42,
    marginTop: 4
  },
  icon4Row: {
    height: 24,
    flexDirection: "row",
    marginTop: 30,
    marginLeft: 30,
    marginRight: 71
  }
});

export default ProfileScreen;
