import * as Animatable from 'react-native-animatable';
import React, { useState, useEffect } from 'react';
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
import MapView, { Marker } from 'react-native-maps';
import * as Location from 'expo-location';

const WidgetMap = () => {

    const [location, setLocation] = useState({coords: {
        latitude: 0,
        longitude: 0
    }});

    useEffect(() => {
    (async () => {
        let { status } = await Location.requestForegroundPermissionsAsync();
        if (status !== 'granted') {
        setErrorMsg('Permission to access location was denied');
        return;
        }
        let location_tmp = await Location.getCurrentPositionAsync({});
        setLocation(location_tmp);
        console.log(location);
    })();
    }, []);

    const coordinate = {
        latitude: location.coords.latitude,
        longitude: location.coords.longitude,
    };
    return(
        <MapView
        style={{ width: '100%', height: '100%', borderRadius: 15}}
        initialRegion={{
            latitude: location.coords.latitude,
            longitude: location.coords.longitude,
            latitudeDelta: 0.01,
            longitudeDelta: 0.01,
        }}>
            <Marker coordinate={coordinate} />
        </MapView>
    );
}

export default WidgetMap;