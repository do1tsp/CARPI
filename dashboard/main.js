function httpGet(theUrl) {
  let xmlHttpReq = new XMLHttpRequest();
  xmlHttpReq.open("GET", theUrl, false); 
  xmlHttpReq.send(null);
  return xmlHttpReq.responseText;
  } 
function Clear() {
  document.getElementById("Home").innerHTML = "";
  document.getElementById("Spotify").innerHTML = "";
  document.getElementById("DAB").innerHTML = "";
  document.getElementById("Settings").innerHTML = "";
}

function addHome() {
  Clear();
  document.getElementById("Home").innerHTML = "Hallo";
  document.getElementById("Home").classList.add("active");
 }
 
function addSpotify() {
  Clear();
  document.getElementById("Spotifynav").classList.add("active");
  var table = document.createElement("table");
  table.setAttribute("class", "table table-dark table-hover Playlist");
  table.setAttribute("id", "playlisttable");          
  document.getElementById("Spotify").appendChild(table);     
  document.getElementById("playlisttable").innerHTML = '<thead></thead> <tbody></tbody>';
  document.getElementById("playlisttable").firstChild.innerHTML = '<tr><th scope="col">#</th><th scope="col">Titel</th><th scope="col">Interpret</th></tr>';
  var playlisttitel = "";
  const json = httpGet('http://localhost:1880/getPlaylist');
  const obj = JSON.parse(json);
  var length = (obj.length-1);
      for (var i = 0; i <= length ; i++) {
      playlisttitel = playlisttitel + '<tr onclick="' + "getSong('" + obj[i].track.id + "') " + '"><th> ' + (i+1) + '</th> <td>' +  obj[i].track.name + '</td> <td>' + obj[i].track.artists[0].name + '</td></tr> ';
    }
  document.getElementById("playlisttable").lastChild.innerHTML = playlisttitel;
  document.getElementById('cover').innerHTML = '<img src="' + httpGet('http://localhost:1880/cover') + '" style="width: 100px; height: 100px;"/>'; 
  document.getElementById('media').innerHTML = httpGet('http://localhost:1880/track');
}

function addDAB(){
  Clear();
  document.getElementById("DAB").innerHTML = 'DAB';
  document.getElementById("dabnav").classList.add("active");
}

function addSettings (){
  Clear();
  document.getElementById("Settings").innerHTML = 'Settings';
  document.getElementById("Settingsnav").classList.add("active");

}
function getSong(id){
  console.log(id);

}
