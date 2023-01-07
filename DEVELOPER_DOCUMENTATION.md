<!-- #######  HEY, I AM THE SOURCE EDITOR! #########-->
<h1 style="color: #5e9ca0;">-----Fejlesztői dokument&aacute;ci&oacute;----</h1>
<h2 style="color: #2e6c80;">1) Az arduino uno k&oacute;dja</h2>
<p>Az arduino mikrokontroller k&oacute;dj&aacute;t illetően a k&oacute;dban szereplő kommentek eg&eacute;szen besz&eacute;desek a műk&ouml;d&eacute;st illetően.</p>
<p>N&eacute;h&aacute;ny fontos dolog:</p>
<p>1. A f&ouml;ld nedvess&eacute;g szenzor AirValue &eacute;s WaterValue &eacute;rt&eacute;k&eacute;t haszn&aacute;lat előtt egy m&eacute;r&eacute;ssel kell elv&eacute;gezni, &uuml;resen kell m&eacute;rni egyet a levegőben valamint a v&iacute;zben &eacute;s kiiratni soilMoistureValue v&aacute;ltoz&oacute;t a soros monitorra.</p>
<p>Ezut&aacute;n a sz&aacute;zal&eacute;k kisz&aacute;m&iacute;t&aacute;sa mappol&aacute;ssal t&ouml;rt&eacute;nik, a soilMoistureValue m&eacute;rt &eacute;rt&eacute;k&eacute;ből, valamint a levegő &eacute;s a v&iacute;z kezdeti ellen&aacute;l&aacute;s&aacute;b&oacute;l m&eacute;rve t&ouml;rt&eacute;nik.</p>
<p>2.A p&aacute;ratartalomhoz &eacute;s a hőm&eacute;rs&eacute;klethez meg kell h&iacute;vni a DHT k&ouml;nyvt&aacute;rat (ezt előtte le kell t&ouml;lteni) (#include "DHT.h"), &eacute;s onnant&oacute;l haszn&aacute;lhat&oacute;v&aacute; v&aacute;lik readHumidity().</p>
<p>3.Az LCD panel műk&ouml;dtet&eacute;s&eacute;hez le kell t&ouml;lteni &eacute;s meg kell h&iacute;vni a sz&uuml;ks&eacute;ges k&ouml;nyt&aacute;rat (#include &lt;LiquidCrystal_I2C.h&gt;)</p>
<p>Ezut&aacute;n a setcursor seg&iacute;ts&eacute;g&eacute;vel be tudjuk &aacute;ll&iacute;tani a k&eacute;pernyő mely pontj&aacute;n kezdj&uuml;k el kiiratni a karaktereket.</p>
<p>4. A felsz&iacute;n nedvess&eacute;gm&eacute;rője eg&eacute;szen egyszerű m&oacute;don műk&ouml;dik, megm&eacute;ri hogy van-e ellen&aacute;l&aacute;s vagy nincs, &eacute;s ez alapj&aacute;n ad vissza egy LOW illetve HIGH jelet, ezekre kell felt&eacute;telt &iacute;rni.</p>
<p>&nbsp;</p>
<p>A v&iacute;zpumpa eg&eacute;szen addig fog műk&ouml;dni am&iacute;g a talajnedvess&eacute;g el nem &eacute;ri a 70%-ot, term&eacute;szetesen az &eacute;rt&eacute;k v&aacute;ltoztat&aacute;s&aacute;val ezt a hat&aacute;rt el tudjuk tolni.</p>
<p>&nbsp;</p>
<p>Legutols&oacute; l&eacute;p&eacute;sben pedig 3 m&eacute;rt adatot (p&aacute;ratartalom, hőm&eacute;rs&eacute;klet &eacute;s talajnedvess&eacute;g) &ouml;sszefűzz&uuml;k &eacute;s ki&iacute;rjuk a soros monitorra hogy &aacute;tadhassuk az ESP-01S eszk&ouml;znek, majd 5 m&aacute;sodpercet v&aacute;runk.</p>
<h2 style="color: #2e6c80;">2) Az ESP-01S k&oacute;dja</h2>
<p>Legelősz&ouml;r hozz&aacute; kell adni mag&aacute;t az eszk&ouml;zt az arduino IDE-hez hogy tudjuk programozni. Ehhez mell&eacute;kelek egy tutorialt (<a href="https://iotcircuithub.com/esp8266-programming-arduino/">https://iotcircuithub.com/esp8266-programming-arduino/</a>).</p>
<p>Az eszk&ouml;z programoz&aacute;sa &uacute;gy n&eacute;z ki hogyha nincs ehhez egy p&aacute;r doll&aacute;ros kis eszk&ouml;z&uuml;nk (esp01 usb programmer) hogy az al&aacute;bbi m&oacute;don kell &ouml;sszek&ouml;tn&uuml;nk az arduinot &eacute;s az ESP modult:</p>
<p>ESP-01S&nbsp; &nbsp; &nbsp;Arduino</p>
<p>3v3 --- 3.3V</p>
<p>RST --- GND</p>
<p>EN --- 3.3V</p>
<p>TX --- TX</p>
<p>RX --- RX</p>
<p>ISO0 --- GND</p>
<p>ISO2 ---</p>
<p>GND --- GND</p>
<p>Fel kell t&ouml;lteni elősz&ouml;r az arduino-ra a felprogramozo_arduinora.ino filet, ezut&aacute;n engedni fogja az tx-rx l&aacute;bakon a felt&ouml;lt&eacute;st az esp modulra.</p>
<p>A sorrend pedig az hogy be kell dugni elősz&ouml;r a GND-be az ISO0 pint, elkezd&uuml;nk fel&ouml;lteni, &eacute;s amikor connecting..... &aacute;llapotban van az eszk&ouml;z, 0.5 m&aacute;sodpercre be kell dugni a GND-be az EN pint &eacute;s gyorsan kih&uacute;zni, ezt a l&eacute;p&eacute;st lehet k&eacute;tszer is meg kell ism&eacute;telni, ezut&aacute;n l&aacute;tni fogjuk hogy elkezd&uuml;nk &iacute;rni az esp eszk&ouml;z mem&oacute;riac&iacute;meire.</p>
<p>Az &aacute;ltal&aacute;nos param&eacute;teres &aacute;t&iacute;r&aacute;sokat a felhaszn&aacute;l&oacute;i dokument&aacute;ci&oacute; tartalmazza (SSD, password, webhook_key).</p>
<p>&nbsp;</p>
<p>Elsők&ouml;rbe fontos megeml&iacute;teni hogy a webhook 3 param&eacute;tert tud &aacute;tadni maximum (ez&eacute;rt is nem az &ouml;sszeset k&uuml;ldj&uuml;k &aacute;t a soros monitoron, csak a relat&iacute;v fontosakat)</p>
<p>A setup r&eacute;szben t&ouml;rt&eacute;nik a wifi h&aacute;l&oacute;zathoz a kapcsol&oacute;d&aacute;s, sz&oacute;val a h&aacute;l&oacute;zatot előtte be kell kapcsolni, a jelenlegi verzi&oacute; nem tartalmazza a jel elveszt&eacute;se eset&eacute;n az &uacute;jracsatlakoz&aacute;s fut&aacute;s k&ouml;zbeni lehetős&eacute;g&eacute;t.</p>
<p>A műk&ouml;d&eacute;se pedig &uacute;gy n&eacute;z ki hogy amint a bufferbe b&aacute;jtok ker&uuml;nek a soros monitorr&oacute;l, karakterenk&eacute;nt beolvassuk a k&uuml;ld&ouml;tt sort, &eacute;s amint egy new line ('\n') karaktert &eacute;szlel&uuml;nk az ad&aacute;st teljesnek tekintj&uuml;k &eacute;s az imm&aacute;r teljes m&eacute;rt&eacute;kben beolvasott sort szegment&aacute;ljuk egy előre defini&aacute;lt karakter alapj&aacute;n (,). A sz&eacute;tt&ouml;rdelt stringeket egy string t&ouml;mbbe t&aacute;roljuk &eacute;s ezut&aacute;n &aacute;tadjuk param&eacute;terk&eacute;nt a webhook.trigger-nek ami elk&uuml;ldi a HTTP k&eacute;r&eacute;st az oldal ir&aacute;ny&aacute;ba.</p>