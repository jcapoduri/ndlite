<?php

$app->get('/ringing/', function() use ($app){    
    global $bluesystem;
    $ret = $bluesystem->readObjectList("ringing");	
	$response = $app->response();
	$response['Content-Type'] = 'application/json';
	if ($ret) {
		$response->write(json_encode($ret));	
	} else {
		\ndlite\badSql();
	};
});

$app->get('/ringing/:id', function($id) use ($app){
	global $bluesystem;
	$ret = $bluesystem->readObject("ringing", $id);
	$response = $app->response();
	$response['Content-Type'] = 'application/json';
	if ($ret) {
		$response->write(json_encode($ret));	
	} else {
		\ndlite\badSql();
	};	
});

$app->post('/ringing', function() use ($app){
	global $bluesystem;
	$json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	}
	$bluesystem->handler->autocommit(FALSE);
	$id = $bluesystem->createObject("ringing", $json);
	if ($id) {
		$bluesystem->handler->commit();
		$app->response()->write($id);
	} else {
		\ndlite\badSql();
	};
});

$app->put('/ringing/:id', function($id) use ($app){
	global $bluesystem;
    $json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	}
	$bluesystem->handler->autocommit(false);
	$ok = $bluesystem->updateObject("ringing", $id, $json);
	if ($ok) {
		$bluesystem->handler->commit();
		//$app->response()->write($id);
	} else {
		\ndlite\badSql();
	};
});

$app->delete('/ringing/:id', function($id) use ($app){
	global $bluesystem;
    $json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	}
	$bluesystem->handler->autocommit(FALSE);
	$id = $bluesystem->createObject("ringing", $json);
	if ($id) {
		$bluesystem->handler->commit();
		$app->response()->write($id);
	} else {
		\ndlite\badSql();
	};
});


?>