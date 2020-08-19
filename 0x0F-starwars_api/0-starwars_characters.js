#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/';

function prom(character){
  return new Promise(function(resolve, reject){
    request(character, function(error, response, body) {
      if (error) {
        reject(error);
      }
        const name = JSON.parse(body).name;
        resolve(name);
    });
  });
}

request(url + process.argv[2], async function (error, response, body) {
  if (error) {
    console.log(error);
  }
  const characters = JSON.parse(body).characters;
  for (const character of characters) {
    console.log(await prom(character));
  }
});