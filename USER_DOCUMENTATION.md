<!-- #######  HEY, I AM THE SOURCE EDITOR! #########-->
<h1 style="color: #5e9ca0;">-----Felhaszn&aacute;l&oacute;i dokument&aacute;ci&oacute;----</h1>
<h2 style="color: #2e6c80;">1) A mikrokontroller &eacute;s a szenzorok k&ouml;z&ouml;tti kapcsolat ki&eacute;p&iacute;t&eacute;se</h2>
<p>K&aacute;belez&eacute;s:</p>
<p><br />Talajnedvess&eacute;g szenzor</p>
<p>szenzor Arduino</p>
<p>VCC --- 5V</p>
<p>GND --- GND</p>
<p>AOUT --- A0 (Analog 0)</p>
<p>&nbsp;</p>
<p>DHT szenzor (Hő &eacute;s p&aacute;ra)</p>
<p>szenzor Arduino</p>
<p>VCC --- 5V</p>
<p>GND --- GND</p>
<p>Digital --- D2 (Digital 2)</p>
<p>&nbsp;</p>
<p>Felsz&iacute;n nedvess&eacute;g szenzor</p>
<p>szenzor Arduino</p>
<p>VCC --- 5V</p>
<p>GND --- GND</p>
<p>D0 --- D4</p>
<p>A0 --- A1</p>
<p>&nbsp;</p>
<p>LCD panel 4x20</p>
<p>szenzor Arduino</p>
<p>VCC --- 5V</p>
<p>GND --- GND</p>
<p>SDA --- SDA</p>
<p>SCL --- SCL</p>
<p>&nbsp;</p>
<p>V&iacute;zpumpa rel&eacute;</p>
<p>Rel&eacute; Arduino</p>
<p>VCC (+) --- 5V</p>
<p>GND (-) --- GND</p>
<p>S --- D9</p>
<p>&nbsp;</p>
<p>ESP-01S wifi modul (haszn&aacute;lat k&ouml;zben)</p>
<p>ESP-01S Arduino</p>
<p>3v3 --- 3.3V (FONTOS!!!!!! MEGHIB&Aacute;SODHAT HA 5V-ra k&ouml;tj&uuml;k)</p>
<p>RST ---</p>
<p>EN --- 3.3V</p>
<p>TX --- RX (D0 uno modellen)</p>
<p>RX --- TX (D1 uno modellen)</p>
<p>IO0 ---</p>
<p>IO2 ---</p>
<p>GND --- GND</p>
<p>&nbsp;</p>
<h2 style="color: #2e6c80;">2) Haszn&aacute;lat</h2>
<p>L&eacute;tre kell hozni a https://twitter.com/ oldalon egy &uacute;j fi&oacute;kot<br />L&eacute;tre kell hozni az https://ifttt.com/ oldalon egy webhookot, amit megfelelő m&oacute;don be kell konfigur&aacute;lni &uacute;gy hogy tweeteljen html k&eacute;r&eacute;s eset&eacute;n<br />Tutorial: https://ifttt.com/connect/maker_webhooks/twitter</p>
<p>Helyes &ouml;sszek&ouml;t&eacute;s eset&eacute;n az 'esp-01s' mapp&aacute;ban tal&aacute;lhat&oacute; esp_01s.ino f&aacute;jlban &aacute;t kell &iacute;rni<br />a webhook kulcs, valamint a csatlakozni k&iacute;v&aacute;nt h&aacute;l&oacute;zatnak a jelszav&aacute;t valamint a h&aacute;l&oacute;zati SSD-t meg kell adni.</p>
<p>Az esp_01s.ino file aj&aacute;n tal&aacute;lhat&oacute; delay-el cs&ouml;kkenthetj&uuml;k illetve n&ouml;velhetj&uuml;k az időtartamot amilyen idők&ouml;zzel műk&ouml;dj&ouml;n a webhook.</p>
<p>Sz&uacute;rjuk a talajnedvess&eacute;g szenzort vir&aacute;gf&ouml;ldbe.</p>
<p>A v&iacute;zpump&aacute;t ne haszn&aacute;ljuk &uuml;resen t&ouml;lts&uuml;nk bele vizet.</p>
<p>Ha mindent j&oacute;l k&ouml;t&ouml;tt&uuml;nk &ouml;ssze a megadott időtartam lej&aacute;rat&aacute;val meg is fognak jelenni a tweetek, a v&iacute;zmpumpa a megadott talajnedvess&eacute;g szint alatt műk&ouml;dni fog, valamint az LCD panel folyamatos &eacute;rtes&iacute;t&eacute;st ny&uacute;jt nek&uuml;nk a m&eacute;r&eacute;sekről.</p>
<p>(megjegyz&eacute;s: az iftt-s webhook-ok egy nap 25x futtathat&oacute;k le)</p>
<p>&nbsp;</p>