<pre>
<?php


$localcodesetraw = file_get_contents("data/codeset.txt");
$localcodeset = json_decode($localcodesetraw);

$server = $localcodeset->server;

$remotecodesetraw = file_get_contents($server."data/codeset.txt");
$remotecodeset = json_decode($remotecodesetraw);
$code = $remotecodeset->code;

foreach($code as $value){

    copy($server."code/".$value,"code/".$value);

}

echo json_encode($code,JSON_PRETTY_PRINT);
    
?>
</pre>
<a href = "index.html">HOME</a>
<style>
a{
    font-size:3em;
}
body{
    font-size:1em;
    font-family:courier;
    color:#00ff00;
    background-color:black;
}
</style>
