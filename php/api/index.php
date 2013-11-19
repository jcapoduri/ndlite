<?php
// CORS enable
header("Access-Control-Allow-Origin: *");
header('Access-Control-Allow-Methods: GET, POST, PUT, DELETE, OPTIONS');
header('Access-Control-Allow-Headers: X-Requested-With');
ini_set('display_errors', 1);

/* 
* necessary files
*/
require 'Slim/Slim.php';
require 'bluesystem/ndlite.php';


/**
* Start the mysqli connection and register a global object
*/

$system_json = file_get_contents('./bluesystem.json');
$system = json_decode($system_json, true);

$bluesystem = new \ndlite\ndlite($system);
//var_dump($bluesystem);
$bluesystem->startApp("web");

\Slim\Slim::registerAutoloader();
$app = new \Slim\Slim();
error_reporting(E_ALL);

$app->get('/', function () use ($app){
    echo "Undefined";
});

//objects
require 'bluesystem/objects/books.php';
require 'bluesystem/objects/business.php';
require 'bluesystem/objects/ringing.php';
require 'bluesystem/objects/clients.php';
require 'bluesystem/objects/jobs.php';
require 'bluesystem/objects/users.php';
require 'bluesystem/objects/workorders.php';
require 'bluesystem/objects/workorder_pages.php';
//relationships

//utils
require 'bluesystem/utils/access.php';

//log
require 'bluesystem/views/log.php';
//include 'bluesystem/relations/booksTree.php';
ini_set('display_errors', 1);
$app->run();
error_reporting(E_ALL);
ini_set('display_errors', 1);

?>