<?php

$app->get('/workorders/', function() use ($app){    
    global $bluesystem;
    $ret = $bluesystem->readObjectList("workorder");	
	$response = $app->response();
	$response['Content-Type'] = 'application/json';
	if ($ret) {
		$response->write(json_encode($ret));	
	} else {
		\ndlite\badSql();
	};
});

$app->get('/workorders/:id', function($id) use ($app){
	global $bluesystem;
	$ret = $bluesystem->readObject("workorder", $id);
	$response = $app->response();
	$response['Content-Type'] = 'application/json';
	if ($ret) {
		$response->write(json_encode($ret));	
	} else {
		\ndlite\badSql();
	};	
});

$app->post('/workorders', function() use ($app){
	global $bluesystem;
	$json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	}
	$bluesystem->handler->autocommit(FALSE);
	$id = $bluesystem->createObject("workorder", $json);
	if ($id) {
		$bluesystem->handler->commit();
		$app->response()->write($id);
	} else {
		\ndlite\badSql();
	};
});

$app->put('/workorders/:id', function($id) use ($app){
	global $bluesystem;
    $json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	}
	$bluesystem->handler->autocommit(false);
	$ok = $bluesystem->updateObject("workorder", $id, $json);
	if ($ok) {
		$bluesystem->handler->commit();
		//$app->response()->write($id);
	} else {
		\ndlite\badSql();
	};
});

$app->delete('/workorders/:id', function($id) use ($app){
	global $bluesystem;
    $json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	}
	$bluesystem->handler->autocommit(FALSE);
	$id = $bluesystem->createObject("workorder", $json);
	if ($id) {
		$bluesystem->handler->commit();
		$app->response()->write($id);
	} else {
		\ndlite\badSql();
	};
});


?>