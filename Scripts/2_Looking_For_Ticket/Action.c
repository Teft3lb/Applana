Action()
{
	
lr_start_transaction("UC_02_looking_for_ticket");

	MainPage();

		lr_think_time(5);

	Login();
	
		lr_think_time(5);

	Flights();

		lr_think_time(5);	

	FindFlight();
	
		lr_think_time(5);
	
	ChooseTicket();
	
		lr_think_time(5);
	
	SignOff();
	
lr_end_transaction("UC_02_looking_for_ticket", LR_AUTO);

	return 0;
}