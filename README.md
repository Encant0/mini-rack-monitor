# Mini Rack Monitor

Arduino alapú rackszekrény hőfigyelő és riasztó rendszer Wokwi szimulációval.

## Projekt célja
A projekt célja egy egyszerű rackszekrény-felügyeleti rendszer készítése, amely
figyeli a hőmérsékletet, kiszámolja az átlagos terhelési állapotot, és riasztást ad
túl magas hőmérséklet vagy nyitott ajtó esetén.

## Funkciók
- DS18B20 digitális hőmérsékletmérés
- LED alapú riasztás
- Slide switch alapú ajtónyitás szimuláció
- Soros monitoros állapotkijelzés
- Wokwi szimulációs demó

## Hardver elemek
- Arduino Uno
- 1 db DS18B20
- 1 db LED
- 1 db soros ellenállás a LED-hez
- 1 db 4.7k ellenállás a DS18B20 felhúzáshoz
- 1 db slide switch

## Pinkiosztás
- D2: DS18B20 adatvonal
- D3: ajtókapcsoló (slide switch)
- D7: riasztó LED

## Működési elv
A rendszer kiolvassa a rack felső zónájának hőmérsékletét a DS18B20 szenzorból.
Ebből számol egy második, modellezett alsó zónát, majd átlagot képez.
Ha az átlaghőmérséklet 30 °C fölé emelkedik, vagy az ajtó nyitottnak érzékelhető,
a rendszer riasztást ad és felkapcsolja a LED-et.

## Wokwi szimuláció
Ide illeszd be a saját Wokwi linkedet.

## Fájlok
- `arduino/MiniRackMonitor.ino` – Arduino program
- `docs/kapcsolas.png` – kapcsolási rajz / screenshot
- `docs/*.png` – működési képernyőképek
- `docs/dokumentacio.pdf` – beadandó dokumentáció

## Használat
1. Nyisd meg a Wokwi projektet.
2. Indítsd el a szimulációt.
3. Állítsd a DS18B20 hőmérsékletét.
4. Kapcsold át a slide switch-et.
5. Figyeld a Serial Monitor kimenetét és a LED állapotát.
