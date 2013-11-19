<?php

$app->get('/jobs/', function() use ($app){    
    global $bluesystem;
    $ret = $bluesystem->readObjectList("job");	
	$response = $app->response();
	$response['Content-Type'] = 'application/json';
	if ($ret) {
		$response->write(json_encode($ret));	
	} else {
		\ndlite\badSql();
	};
});

$app->get('/jobs/:id', function($id) use ($app){
	global $bluesystem;
	$ret = $bluesystem->readObject("job", $id);
	$response = $app->response();
	$response['Content-Type'] = 'application/json';
	if ($ret) {
		$response->write(json_encode($ret));	
	} else {
		\ndlite\badSql();
	};	
});

$app->post('/jobs', function() use ($app){
	global $bluesystem;
	$json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	}
	$bluesystem->handler->autocommit(FALSE);
	$id = $bluesystem->createObject("job", $json);
	if ($id) {
		$bluesystem->handler->commit();
		$app->response()->write($id);
	} else {
		\ndlite\badSql();
	};
});

$app->put('/jobs/:id', function($id) use ($app){
	global $bluesystem;
    $json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	}
	$bluesystem->handler->autocommit(false);
	$ok = $bluesystem->updateObject("job", $id, $json);
	if ($ok) {
		$bluesystem->handler->commit();
		//$app->response()->write($id);
	} else {
		\ndlite\badSql();
	};
});

$app->delete('/jobs/:id', function($id) use ($app){
	global $bluesystem;
    $json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	}
	$bluesystem->handler->autocommit(FALSE);
	$id = $bluesystem->createObject("job", $json);
	if ($id) {
		$bluesystem->handler->commit();
		$app->response()->write($id);
	} else {
		\ndlite\badSql();
	};
});


?>