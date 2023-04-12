# Effective-Plant-Growth


~Effective-Plant-Growth-Esp8266 "24/7 Online"<br>
~Effective-Plant-Growth-Esp8266-with-deep-sleep "Every 24 hours, it wakes up, creates a server with JSON, and then goes back to sleep."

This program sets up a web server that listens on port 80 and responds to incoming HTTP requests with a JSON object that contains the moisture level of the soil as read by the sensor.

You will need to replace your_SSID and your_PASSWORD with the credentials for your Wi-Fi network.

Once the program is uploaded to your ESP8266 and it is connected to your Wi-Fi network, you can access the moisture level data by navigating to the ESP8266's IP address in a web browser. For example, if your ESP8266 has the IP address 192.168.1.100, you would navigate to http://192.168.1.100/ to see the moisture level in JSON format.

Other websites can use this data as an API by sending a GET request to your ESP8266's IP address and parsing the JSON response.



<a href="https://www.buymeacoffee.com/Eyonic" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png" alt="Buy Me A Coffee" style="height: 41px !important;width: 174px !important;box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;-webkit-box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;" ></a>
