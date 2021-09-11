Action()
{
	
lr_start_transaction("UC_02_looking_for_ticket");

	MainPage();

		lr_think_time(6.3);

	Login();
	
		lr_think_time(6.3);
		
	Itinerary();
	
		lr_think_time(6.3);

	Flights();

		lr_think_time(6.3);	

	FindFlight_rnd();
	
		lr_think_time(6.3);
	
	ChooseTicket_rnd();
	
		lr_think_time(6.3);
	
	Itinerary();
	
	
	SignOff();
	
lr_end_transaction("UC_02_looking_for_ticket", LR_AUTO);

	return 0;
}