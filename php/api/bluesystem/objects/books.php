<?php

$app->get('/books/', function() use ($app){	
	global $bluesystem;
	$ret = $bluesystem->readObjectList("book");	
	$response = $app->response();
	$response['Content-Type'] = 'application/json';
	if ($ret !== false) {
		$response->write(json_encode($ret));	
	} else {
		\ndlite\badSql();
	};
});

$app->get('/books/:id', function($id) use ($app){
	global $bluesystem;
	$ret = $bluesystem->readObject("book", $id);
	$response = $app->response();
	$response['Content-Type'] = 'application/json';
	if ($ret !== false) {
		$response->write(json_encode($ret));	
	} else {
		\ndlite\badSql();
	};	
});

$app->post('/books', function() use ($app){
	global $bluesystem;
	$json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	}
	$bluesystem->handler->autocommit(FALSE);
	$id = $bluesystem->createObject("book", $json);
	if ($id) {
		$bluesystem->handler->commit();
		$app->response()->write($id);
	} else {
		\ndlite\badSql();
	};
});

$app->put('/books/:id', function($id) use ($app){
	global $bluesystem;
    $json = json_decode($app->request()->getBody(), true);
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	}
	$bluesystem->handler->autocommit(false);
	$ok = $bluesystem->updateObject("book", $id, $json);
	if ($ok) {
		$bluesystem->handler->commit();
		//$app->response()->write($id);
	} else {
		\ndlite\badSql();
	};
});

$app->delete('/books/:id', function($id) use ($app){
	global $bluesystem;
    
	if (is_null($json)) {
		\ndlite\badJSON();
		return;
	};
	
	return $bluesystem->deleteObject("book", $id);
	
});


?>