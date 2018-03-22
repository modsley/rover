#pragma once
void imuTest() {
	imu.begin();    // ���������� ������ � ��������� ������� sensor.
	if (DEBUG) {
		switch (imu.test()) { // �������� ��������� ���������������� ��� ��� ��������� � ���������� ���� �����������.
		case 0:
			Serial.println(
					"���������� ���������������� ���� �������� ������� ��������!");
			break;
		case BMA_ERR_ID:
			Serial.println("������������ �� ������.");
			break;
		case BMG_ERR_ID:
			Serial.println("�������� �� ������.");
			break;
		case BMM_ERR_ID:
			Serial.println("����������� �� ������.");
			break;
		case BMA_ERR_ST:
			Serial.println("������������ �� ������ ����������������.");
			break;
		case BMG_ERR_ST:
			Serial.println("�������� �� ������ ����������������.");
			break;
		case BMM_ERR_ST:
			Serial.println("����������� �� ������ ����������������.");
			break;
		default:
			Serial.println(
					"������ �� ������ ���������������� �� ����������� �������.");
			break;
		}
	} else {
		imu.test();
	}
}
