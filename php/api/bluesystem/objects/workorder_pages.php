<?php

$app->get('/workorder_pages/', function() use ($app){    
    global $bluesystem;
    $ret = $bluesystem->readObjectList("workorder_page");	
	$response = $app->response();
	$response['Content-Type'] = 'application/json';
	if ($ret) {
		$response->write(json_encode($ret));	
	} else {
		\ndlite\badSql();
	};
});

$app->get('/workorder_pages/:id', function($id) use ($app){
	global $bluesystem;
	$ret = $bluesystem->readObject("workorder_page", $id);
	$response = $app->response();
	$response['Content-Type'] = 'application/json';
	if ($ret) {
		$response->write(json_encode($ret));	
	} else {
		\ndlite\badSql();
	};	
});

$app->post('/workorder_pages', function() use ($app){
	global $bluesystem;
	$json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	}
	$bluesystem->handler->autocommit(FALSE);
	$id = $bluesystem->createObject("workorder_page", $json);
	if ($id) {
		$bluesystem->handler->commit();
		$app->response()->write($id);
	} else {
		\ndlite\badSql();
	};
});

$app->put('/workorder_pages/:id', function($id) use ($app){
	global $bluesystem;
    $json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	}
	$bluesystem->handler->autocommit(false);
	$ok = $bluesystem->updateObject("workorder_page", $id, $json);
	if ($ok) {
		$bluesystem->handler->commit();
		//$app->response()->write($id);
	} else {
		\ndlite\badSql();
	};
});

$app->delete('/workorder_pages/:id', function($id) use ($app){
	global $bluesystem;
    $json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	}
	$bluesystem->handler->autocommit(FALSE);
	$id = $bluesystem->createObject("workorder_page", $json);
	if ($id) {
		$bluesystem->handler->commit();
		$app->response()->write($id);
	} else {
		\ndlite\badSql();
	};
});


?>