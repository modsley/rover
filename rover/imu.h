#pragma once
void imuTest() {
	imu.begin();    // Инициируем работу с датчиками объекта sensor.
	if (DEBUG) {
		switch (imu.test()) { // Получаем результат самотестирования для его сравнения с указанными ниже константами.
		case 0:
			Serial.println(
					"Аппаратное самотестирование всех датчиков успешно пройдено!");
			break;
		case BMA_ERR_ID:
			Serial.println("Акселерометр не найден.");
			break;
		case BMG_ERR_ID:
			Serial.println("Гироскоп не найден.");
			break;
		case BMM_ERR_ID:
			Serial.println("Магнитометр не найден.");
			break;
		case BMA_ERR_ST:
			Serial.println("Акселерометр не прошел самотестирование.");
			break;
		case BMG_ERR_ST:
			Serial.println("Гироскоп не прошел самотестирование.");
			break;
		case BMM_ERR_ST:
			Serial.println("Магнитометр не прошел самотестирование.");
			break;
		default:
			Serial.println(
					"Модуль не прошел самотестирование по неизвестной причине.");
			break;
		}
	} else {
		imu.test();
	}
}
