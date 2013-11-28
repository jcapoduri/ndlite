<?php

/**
* Connection singleton
*/
namespace NdLite;

class Connection {
	private static $_instance = 0;
	private $_dbname = 'fotocasi_bluesystem';
	private $_dbpass = 'lokithor';
	private $_dbuser = 'fotocasi_user';
	private $_dbhost = 'localhost';
	private $_handler = null;

	public static function init($dbhost, $dbuser = "", $dbpass = "", $dbname = ""){		
		if(!self::$_instance) self::$_instance = new Connection();
		if(is_array($dbhost)){
			self::$_instance->_dbhost = $dbhost["host"];
			self::$_instance->_dbuser = $dbhost["user"];
			self::$_instance->_dbpass = $dbhost["pass"];
			self::$_instance->_dbname = $dbhost["database"];
		}else{
			self::$_instance->_dbhost = $dbhost;
			self::$_instance->_dbuser = $dbuser;
			self::$_instance->_dbpass = $dbpass;
			self::$_instance->_dbname = $dbname;
		};
	}

	public static function connect(){
		self::$_instance->_handler = new \mysqli(
			self::$_instance->_dbhost, 
			self::$_instance->_dbuser, 
			self::$_instance->_dbpass, 
			self::$_instance->_dbname
		);
		return (self::$_instance->_handler->errno == 0);
	}

	public static function instance(){
		if(!self::$_instance) self::$_instance = new Connection();
		return self::$_instance;		
	}

	public function disconnect(){
		return self::$_instance->_handler->close();
	}

	public static function query($query){
		return self::$_instance->_handler->query($query);
	}

	public static function lastInsertedId(){
		return self::$_instance->_handler->insert_id;
	}

	private function __construct(){
		//return self::$_instance->_handler->errno;	
	}

};

?>