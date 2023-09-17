import React from 'react';
import { View, Text, TouchableOpacity, Image, StyleSheet } from 'react-native';

const HeaderCalandar = () => {
  return (
    <View style={styles.headerContainer}>
      <TouchableOpacity>
        <Image
          source={require('../assets/barre.png')}
          style={styles.menuIcon}
        />
      </TouchableOpacity>
      <Text style={styles.headerText}>Date</Text>
      <TouchableOpacity>
        <Image
          source={require('../assets/loupe.png')}
          style={styles.loopIcon}
        />
      </TouchableOpacity>
      <TouchableOpacity>
        <Image
          source={require('../assets/menu.png')}
          style={styles.verticalDotsIcon}
        />
      </TouchableOpacity>
    </View>
  );
};

const styles = StyleSheet.create({
  headerContainer: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    alignItems: 'center',
    backgroundColor: '#b3b3ff', // Couleur de fond de l'en-tête
    paddingHorizontal: 16,
    paddingVertical: 0,
    width: '100%',
    height: 100,
    position: 'absolute',
    zIndex: 1,
  },
  menuIcon: {
    width: 24,
    height: 24,
    tintColor: 'white',
    marginTop: 40,
  },
  loopIcon: {
    width: 24,
    height: 24,
    tintColor: 'white',
    marginTop: 40,

  },
  verticalDotsIcon: {
    width: 24,
    height: 24,
    tintColor: 'white',
    marginTop: 40,

  },
  headerText: {
    fontSize: 18,
    fontWeight: 'bold',
    color: 'white',
    marginTop: 40,
    marginRight: 150,

  },
});

export default HeaderCalandar;
