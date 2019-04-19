<?php
/**
 * Created by PhpStorm.
 * User: wuhanyu
 * Date: 2019-04-17
 * Time: 21:17
 */

class Cat
{
    var $name;
    var $age;

    function setName($name){
        $this ->name = $name;
    }

    function eat(){
        echo $this->name . 'is eating.';
    }
}

$cat1 = new Cat();
$cat1->setName('mimi');
$cat1->eat();


$cat2 = new Cat();
$cat2->setName('haha');
$cat2->eat();