Action()
{


lr_start_transaction("UC_04_Delete_ticket");
		
	MainPage();
	
		lr_think_time(6);
		
	Login();
	
		lr_think_time(6);
	
	Itinerary();
	
		lr_think_time(6);

	ChooseTicketForDelete();
		
		lr_think_time(6);
		
	SignOff();

lr_end_transaction("UC_04_Delete_ticket",LR_AUTO);

	return 0;
}