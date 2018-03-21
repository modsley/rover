#pragma once
//Threads
Thread BTConnectionData = Thread(); //Establish and process BT Connection commands
ThreadController omlController = ThreadController(); // controller for threads out of main loop

ThreadController mainController = ThreadController();

void InitThreads(){
	BTConnectionData.enabled = true;
	BTConnectionData.setInterval(100);
	BTConnectionData.onRun(BTConnection);
	omlController.add(&BTConnectionData);

}
