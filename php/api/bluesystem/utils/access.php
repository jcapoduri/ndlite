<?php

//log in for admin user
$app->post('/login', function() use ($app){
    global $bluesystem;
    $json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	};
});

//log out for admin user
$app->delete('/login', function() use ($app){
    
});

//log in for user
$app->post('/business/:id/login', function($id) use ($app){
    global $bluesystem;
    $json = json_decode($app->request()->getBody(), true);
    if (is_null($json)) {
		\ndlite\badJSON();
		return;
	};
    $response = $app->response();
    
    $query = "SELECT id FROM `users` WHERE MD5(DES_DECRYPT(`password`, 'lokithor')) LIKE '" . $json["password"] . "' AND username LIKE '" . $json["username"] . "'";
    $query .= " AND id IN (SELECT child FROM business_users WHERE father = " . $id . ")";
    
    $res = $bluesystem->handler->query($query);
    if($row = $res->fetch_assoc()) {        
        $res = $bluesystem->handler->query("SELECT id FROM `userstamp` WHERE business = " . $id . " AND user_id = " .  $row["id"] . " AND endstamp = '0000-00-00 00:00:00'");
        if (!$res->fetch_assoc())
            $bluesystem->handler->query("INSERT INTO `userstamp` (business, user_id, initstamp, endstamp, token) VALUES (" . $id . ", " . $row["id"] . ", CURRENT_TIMESTAMP, '0000-00-00 00:00:00', MD5('" . $row["id"] . microtime()  . "'))");
            
        $ret = $bluesystem->readObject("user", $row["id"]);
        
    	$response['Content-Type'] = 'application/json';
    	if ($ret) {
    		$response->write(json_encode($ret));
    	} else {
    		\ndlite\badSql();
    	};
    } else {
        $response->write(-1);
    };
});

//log out for admin user
$app->delete('/business/:id/login/:uid', function($id, $uid) use ($app){
    global $bluesystem;
    $res = $bluesystem->handler->query("UPDATE `userstemp` SET endstamp = CURRENT_TIMESTAMP  WHERE endstamp = '0000-00-00 00:00:00' AND business = " . $id . " AND user_id = " . $uid);
    return $res;    
});


?>