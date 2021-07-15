# C Socket GET Request

*© Israel Pereira Tavares da Silva*

> You hear talk of “sockets” all the time, and perhaps you are wondering just what they are exactly. Well, they’re this: a way to speak to other programs using standard Unix file descriptors.

* [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/html/)
* [openweathermap.org](https://openweathermap.org)

`get.c` is a program that builds a GET request to `api.openweathermap.org` to fetch the weather forecast for Florianopolis. The program was build while reading the excellent [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/html/) which is available on the cutting edge website [beej.us](https://beej.us/). 

To run the program an API key needs to be added to `get.c`:

```c
  const char APIKey[] = "";
```

Go to [openweathermap.org/api_keys](https://home.openweathermap.org/api_keys) and create a new key to use with the program.

 ```c
  const char APIKey[] = "YourAPIKeyHere";
 ```

Compile and  run the program.

```bash
cc get.c && ./a.out
```

Sample output:

```bash
HTTP/1.1 200 OK
Server: openresty
Date: Thu, 15 Jul 2021 23:38:49 GMT
Content-Type: application/json; charset=utf-8
Content-Length: 500
Connection: keep-alive
X-Cache-Key: /data/2.5/weather?q=florianopolis
Access-Control-Allow-Origin: *
Access-Control-Allow-Credentials: true
Access-Control-Allow-Methods: GET, POST

{"coord":{"lon":-48.5012,"lat":-27.6146},"weather":[{"id":803,"main":"Clouds","description":"broken clouds","icon":"04n"}],"base":"stations","main":{"temp":291.96,"feels_like":291.91,"temp_min":290.58,"temp_max":292.72,"pressure":1011,"humidity":77},"visibility":10000,"wind":{"speed":0.45,"deg":132,"gust":1.79},"clouds":{"all":75},"dt":1626392031,"sys":{"type":2,"id":2012878,"country":"BR","sunrise":1626343390,"sunset":1626381384},"timezone":-10800,"id":6323121,"name":"Florianópolis","cod":200}

```

> "Rain beats the leopard’s skin but it does not wash out the spots". Old habits die hard. If you are known in your community for one thing  (especially, that which is bad), it will be very difficult for the  society to change its opinion about you even if you one day do good  things. Impressions count a lot. (Proverb from Ghana)

