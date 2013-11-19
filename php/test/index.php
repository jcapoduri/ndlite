<?php
// CORS enable
header("Access-Control-Allow-Origin: *");
header('Access-Control-Allow-Methods: GET, POST, PUT, DELETE, OPTIONS');
header('Access-Control-Allow-Headers: X-Requested-With');
ini_set('display_errors', 1);

/* 
* necessary files
*/
require '../api/ndlite/nd.php';
require '../api/Slim/Slim.php';
require '../api/bluesystem/ndlite.php';

/**
* Start the mysqli connection and register a global object
*/

$system_json = file_get_contents('./test.json');
$system = json_decode($system_json, true);

$bluesystem = new \ndlite\ndlite($system);
$bluesystem->startApp("web");

\Slim\Slim::registerAutoloader();
$app = new \Slim\Slim();


$app->get('/', function () use ($app){
	$response = $app->response();
	$response->write("{}");
});

$app->get('/a', function () use ($app){
	$response = $app->response();
	$response->write("{}");
});

$app->run();
?>