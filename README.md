# MQTT  

file -> mosquitto.conf

il file può essere posizionato dove si preferisce, basta che mosquitto abbia i permessi per accedervi

```allow_anonymous false``` -> non permette anonimi, richiede auth
```password_file /etc/mosquitto/password_file``` -> percorso del file delle password per auth

per creare un password_file si usa il comando:   
```
mosquitto_passwd -c /etc/mosquitto/password_file utente1
```

per aggiungere un utente ad un file già esistente si usa:
```
mosquitto_passwd /etc/mosquitto/password_file utente2
```

abbiamo 4 breadboard, 2 wifiesp-wroom-32,2 kintone cable v2 for type-c

pc   -> browser,ide esp 32
rpi  -> mosquitto,node red,webdashboard
esp32-> sensori,attuatori
esp32-> sensori,attuatori

per i topic di default mettiamo /gruppo4 e poi i topic partono da li es /gruppo4/sensori

gli esp 32 con i led e quelli con i bottoni mandano solo i loro topic e i loro dati.
Ci sarà un applicativo esterno che gestirà la connessione tra ogni topic e gestisce la business logic.

in mqtt se scrivo gruppo3/+/led posso fare il subscribe a tutto quello che fa il match al 1 e 3 livello, indipendentemente dal secondo
se invece scrivo gruppo3/# posso fare il subscribe di tutto quello che fa il match del 1