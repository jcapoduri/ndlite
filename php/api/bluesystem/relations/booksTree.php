<?php

$app->get('/books/:id/books', function($id) use ($app){	
	global $storage;
	$query = \lite\readFromRelation("books", "books", $id, "books_tree", "book_root", "book_leaf");
	$res = $storage->query($query);
	$ret = array();
	while ($row = $res->fetch_assoc()) {
	    array_push($ret, $row);
	};
	$response = $app->response();
	$response['Content-Type'] = 'application/json';
	$response->write(json_encode($ret));
});

?>