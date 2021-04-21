function httpGet(theUrl) {
    let xmlHttpReq = new XMLHttpRequest();
    xmlHttpReq.open("GET", theUrl, false); 
    xmlHttpReq.send(null);
    return xmlHttpReq.responseText;
  } // Function um mit NodeRed zu Sprechen

  window.onload = console.log(httpGet('http://localhost:1880/track')); // Titel - Künstler
  window.onload = document.getElementById('Cover').innerHTML = '<img src="' + httpGet('http://localhost:1880/cover') + '"style="width: 100px; height: 100px;"/>'; // Setzt das Cover in das DIV Cover
  
  // Titellänge
  const duration = httpGet('http://localhost:1880/duration');
  const datum_duration = new Date(1970,1,1,0,0,0, duration);      
  window.onload = console.log(datum_duration.getMinutes());
  window.onload = console.log(datum_duration.getSeconds());

  // Aktuelle Titelzeit
  const progress = httpGet('http://localhost:1880/progress');
  const datum_progress = new Date(1970,1,1,0,0,0, progress);      
  window.onload = console.log(datum_progress.getMinutes());
  window.onload = console.log(datum_progress.getSeconds());

  // Zeitanzeige
  window.onload = document.getElementById('Uhr-Zeit').innerHTML = '<p>' + '12' + ':' + '00' + '</p>'; // Setzt die Uhrzeit
  window.onload = document.getElementById('Uhr-Datum').innerHTML = '<p>' + '21.04.2021' + '</p>'; // Setzt das Datum