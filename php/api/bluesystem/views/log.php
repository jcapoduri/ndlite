<?php

//user access

$app->get('/business/:id/loggeduser', function($id) use ($app) {
    global $bluesystem;
    
    $res = $bluesystem->handler->query("SELECT DISTINCT user_id FROM userstamp WHERE endstamp = '0000-00-00 00:00:00' AND business = " . $id);
    $ret = array();    
    
    while ($row = $res->fetch_assoc()) {        
        $obj = $bluesystem->readObject("user", $row["user_id"]);        
        array_push($ret, $obj);
    };
    
    $response = $app->response();
	$response['Content-Type'] = 'application/json';
	$response->write(json_encode($ret));
});

$app->post('/business/:id/closeday', function($id) use ($app){
    global $bluesystem;
    $json = json_decode($app->request()->getBody(), true);
    $date = (isset($json["closestamp"])) ? "'" . $json["closestamp"] . "'" : "CURRENT_TIMESTAMP";
    $res = $bluesystem->handler->query("UPDATE `userstemp` SET endstamp = " . $date . "  WHERE endstamp = '0000-00-00 00:00:00' AND business = " . $id);
    
    $response = $app->response();
    $response['Content-Type'] = 'application/json';
	$response->write(json_encode($ret));
});


//users daylog

$app->get('/business/:id/workhours', function($id) use ($app){
    
});
?>