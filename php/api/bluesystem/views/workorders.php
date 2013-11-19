<?php

$app->get('/workorder/:id/job', function($bid, $jid, $wid) use ($app){
    global $bluesystem;
    $ret = $bluesystem->parentRelation("workorderJobs", $id);
	$response = $app->response();
	$response['Content-Type'] = 'application/json';
	if ($ret) {
		$response->write(json_encode($ret));	
	} else {
		\ndlite\badSql();
	};	
});

/*$app->get('/business/:bid/jobs/:jid/workorder/:wid', function($bid, $jid, $wid) use ($app){
    global $bluesystem;
	$ret = $bluesystem->readObject("workorder", $id);
	$response = $app->response();
	$response['Content-Type'] = 'application/json';
	if ($ret) {
		$response->write(json_encode($ret));	
	} else {
		\ndlite\badSql();
	};	
});*/

?>