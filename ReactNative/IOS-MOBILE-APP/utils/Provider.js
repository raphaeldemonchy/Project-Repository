import React, { createContext, useState } from 'react';

const MyContext = createContext();

const MyProvider = ({ children }) => {
  const [data, setData] = useState({
    me: {},
    employee: [{}],
    employeeTmp: [{}],
    imageData: [{}],
    conversations: [{}],
    ceo: {},
    coords: {
      latitude: 0,
      longitude: 0
    },
    weathers: {},
    news: [{}],
    events: [{}],
  });

  const updateEventsData = (newEventsData) => {
    setData((prevData) => ({
      ...prevData,
      events: newEventsData,
    }));
  };

  const updateNewsData = (newNewsData) => {
    setData((prevData) => ({
      ...prevData,
      news: newNewsData,
    }));
  };

  const updateWeatherData = (newWeatherData) => {
    setData((prevData) => ({
      ...prevData,
      weather: newWeatherData,
    }));
  }

  const updateProfileData = (myProfileData) => {
    setData((prevData) => ({
      ...prevData,
      me: myProfileData,
    }));
  };

  const getEmployeesData = () => {
   return (data.employee);
  };

  const updateConversationsData = (myConversations) => {
    setData((prevData) => ({
      ...prevData,
      conversations: myConversations,
    }));
  };

  const updateEmployeeData = (newEmployeeData) => {
    setData((prevData) => ({
      ...prevData,
      employee: newEmployeeData,
    }));
  };

  const updateEmployeeTmpData = (newEmployeeTmpData) => {
    setData((prevData) => ({
      ...prevData,
      employeeTmp: newEmployeeTmpData,
    }));
  };

  const updateCeoData = (newCeoData) => {
    setData((prevData) => ({
      ...prevData,
      ceo: newCeoData,
    }));
  };

  const updateImageData = (newImageData) => {
    setData((prevData) => ({
      ...prevData,
      imageData: newImageData,
    }));
  };

  const updateCoordsData = (newCoordsData) => {
    setData((prevData) => ({
      ...prevData,
      coords: newCoordsData,
    }));
  }

  return (
    <MyContext.Provider value={{ data, getEmployeesData,
    updateConversationsData,
    updateEmployeeData,
    updateImageData,
    updateEmployeeTmpData,
    updateProfileData,
    updateCeoData,
    updateCoordsData,
    updateWeatherData,
    updateEventsData,
    updateNewsData}}>
      {children}
    </MyContext.Provider>
  );
};

export { MyProvider, MyContext };
