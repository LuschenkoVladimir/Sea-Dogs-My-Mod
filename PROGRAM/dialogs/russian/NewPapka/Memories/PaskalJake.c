
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		
	case "First Time":
    dialog.text = "";
    link.l1 = "";
    link.l1.go = "dialog1";
    break;  	
		
		
		
	case "PaskalJakeSharlieGuberWife_1":
    dialog.text = "Месье де Мор? Меня к вам направил шевалье де Валинье. Он сказал, что теперь я буду служить под вашим командованием. Меня зовут Паскаль Жаке.";
    link.l1 = "Грегуар  обещал, что направит ко мне человека с опытом мореплавания и морского боя.";
    link.l1.go = "PaskalJakeSharlieGuberWife_2";
    break;  


    case "PaskalJakeSharlieGuberWife_2":
    dialog.text = "Совершенно верно, месье. Шевалье упомянул, что вы располагаете небольшим судном типа люггера или шлюпа, и вам предстоит немного попугать местных контрабандистов, хе-хе.";
    link.l1 = "Ха-ха, ну вроде того. Ну либо им предстоит немного попугать нас, а нам придётся отступить под защиту местного форта.";
    link.l1.go = "PaskalJakeSharlieGuberWife_3";
    break;


    case "PaskalJakeSharlieGuberWife_3":
    dialog.text = "На вашем месте, месье де Мор, я бы не был столь большим пессимистом, хе-хе. Управлять фрегатом, пожалуй, я не смогу, но даже на небольшом корабле при должном оснащении от контрабандистов нам бегать не придётся.";
    link.l1 = "Хорошо, тогда добро пожаловать в команду. Правда её ещё нет, да и корабль у местного корабела я пока не выкупил.";
    link.l1.go = "PaskalJakeSharlieGuberWife_4";
    break;


    case "PaskalJakeSharlieGuberWife_4":
    dialog.text = "Тогда предлагаю разделить функции. Вы пока отправляйтесь к корабелу и утрясайте с ним финансовые вопросы, а я направлюсь в таверну и посмотрю, какую команду можно нанять в этом городишке.";
    link.l1 = "Договорились, Паскаль. Тем более я мало что смыслю в найме матросов. ";
    link.l1.go = "PaskalJakeSharlieGuberWife_exit1";
    break;

    case "PaskalJakeSharlieGuberWife_exit1":
	DialogExit();
	AddDialogExitQuest("GuberWife_44");
	break;	


    case "PaskalJakeSharlieGuberWife_5":
    dialog.text = "Ну что, месье де Мор, вы уладили вопрос с кораблём?";
    link.l1 = "Да, он уже стоит в порту Сен-Пьера. А что с матросами?";
    link.l1.go = "PaskalJakeSharlieGuberWife_6";
    break;

    case "PaskalJakeSharlieGuberWife_6":
    dialog.text = "Как я предполагал, здесь мы вполне можем нанять приличную команду. Побеседуйте вон с тем матросом за дальним столиком. Он из группы списанных на берег с одного купеческого судна и не производит впечатления салаги в нашем деле.";
    link.l1 = "Хорошо, Паскаль, полагаюсь на ваше мнение. Можете пока отправиться осмотреть корабль.";
    link.l1.go = "PaskalJakeSharlieGuberWife_exit2";
    break;


    case "PaskalJakeSharlieGuberWife_exit2":
	DialogExit();
	AddDialogExitQuest("GuberWife_48");
	break;


    case "Folke_6":
			pchar.GenQuest.StoreGoods.StoreIdx = Fortfrance_STORE;
			pchar.GenQuest.StoreGoods.Starting = true; // заполняем магазин 250912
			dialog.text = "Отличный люггер, капитан. Полагаю, для контрабандистов настали чёрные дни, хе-хе.";
			link.l1 = "Очень хорошо. По крайней мере, деньги не пропали даром... Паскаль, будут Какие-нибудь советы перед тем как отправиться в путь?";
			link.l1.go = "Folke_8";
		break;
		
		case "Folke_7":
			dialog.text = "Да уж, этот шлюп основательно повреждён, капитан. Для перехода до Гваделупы он с большего годен, но по прибытии в Бас-Тер нужно сразу поставить его на ремонт.";
			link.l1 = "У меня не было выбора - на верфи предложили только эту посудину. Да ещё и содрали приличную сумму, а чинить её, понимаешь ли, времени у них нет... Паскаль, будут Какие-нибудь советы перед тем как отправиться в путь?";
			link.l1.go = "Folke_8";
		break;
		
		bOk = (GetSquadronGoods(pchar, GOOD_BALLS) >= 80) && (GetSquadronGoods(pchar, GOOD_GRAPES) >= 80) && (GetSquadronGoods(pchar, GOOD_KNIPPELS) >= 80) && (GetSquadronGoods(pchar, GOOD_BOMBS) >= 80) && (GetSquadronGoods(pchar, GOOD_POWDER) >= 180);
		case "Folke_8":
			if (bOk)
			{
				dialog.text = "Ну, боеприпасами вы запаслись достаточно, капитан. Этого арсенала нам хватит вполне, только не забывайте своевременно пополнять его.";
				link.l1 = "Конечно, это же само собой разумеется. Ещё какие-то замечания?";
				link.l1.go = "Folke_10";
			}
			else
			{
				dialog.text = "Я осмотрел трюм, капитан. У нас недостаточно боеприпасов. Нужно как минимум по сто штук ядер, книппелей и бомб, а также сто порций картечи и пороха на двести выстрелов. Закупите необходимый арсенал, капитан - всё это не будет стоить дорого, зато спасёт наши жизни в случае нападения пиратов или испанцев.";
				link.l1 = "Хорошо. Я последую твоему совету. Отправляюсь на берег.";
				link.l1.go = "Folke_9";
			}
		break;
		
		case "Folke_9":
			DialogExit();
			NextDiag.CurrentNode = "Folke_goods_1";
			LAi_SetStayType(npchar);
			AddQuestRecord("Sharlie", "12");
		break;
		
		case "Folke_goods_1":
			dialog.text = "Вы закончили закупку амуниции, капитан?";
			if (bOk)
			{
				link.l1 = "Да, закончил. Ещё какие-то замечания?";
				link.l1.go = "Folke_10";
			}
			else
			{
				link.l1 = "Нет, я ещё этим занимаюсь.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Folke_goods_1";
			}
		break;
		
		bOk = (GetSquadronGoods(pchar, GOOD_WEAPON) >= 50);
		case "Folke_10":
			if (bOk)
			{
				dialog.text = "Оружия для команды вы закупили достаточно, и правильно сделали - не дай Бог рукопашная - не голыми же руками драться. Не забывайте проверять его количество, потому что безоружный матрос - это мёртвый матрос\nИ лучше держать оружие с запасом, ибо проклятые крысы любят грызть рукояти сабель и пистолей, приводя их в негодность.";
				link.l1 = "Понятно. Вижу, ты ещё что-то хочешь сказать?";
				link.l1.go = "Folke_11";
			}
			else
			{
				dialog.text = "У нас нехватка оружия для матросов. Не дай Бог рукопашная - что им, голыми руками драться? Безоружный матрос - это мёртвый матрос. Как я понял, у вас сорок человек экипажа\nНужно купить оружие каждому, и лучше с запасом, комплектов пятьдесят, ибо проклятые крысы любят грызть рукояти сабель и пистолей, приводя их в негодность.";
				link.l1 = "Так и поступим. Скоро вернусь.";
				link.l1.go = "Folke_10_1";
			}
		break;
		
		case "Folke_10_1":
			DialogExit();
			NextDiag.CurrentNode = "Folke_goods_2";
			LAi_SetStayType(npchar);
			AddQuestRecord("Sharlie", "13");
		break;
		
		case "Folke_goods_2":
			dialog.text = "Вы закончили закупку оружия, капитан?";
			if (bOk)
			{
				link.l1 = "Оружие в трюме. Вижу, ты ещё что-то хочешь сказать?";
				link.l1.go = "Folke_11";
			}
			else
			{
				link.l1 = "Нет, я ещё этим занимаюсь.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Folke_goods_2";
			}
		break;
		
		bOk = (GetSquadronGoods(pchar, GOOD_FOOD) >= 100) && (GetSquadronGoods(pchar, GOOD_RUM) >= 10);
		case "Folke_11":
			if (bOk)
			{
				dialog.text = "Наверное, больше ничего. Провизии у нас достаточно, о роме для команды вы тоже позаботились - очень хорошо, так как нет лучшего лекарства от всех хворей, как добрая кружка рому после вахты. Матросы любят и уважают капитанов, выдающих ежедневные порции рома...";
				link.l1 = "Ну, как я понял, мы можем смело отправляться в путь?";
				link.l1.go = "Folke_12";
			}
			else
			{
				dialog.text = "Да. Это касается провианта и рома. Если на корабле мало провианта - это плохо. Никогда не знаешь, на сколько затянется рейс - штиль или шторм могут нарушить все планы. А если закончится еда - быть беде: голодный бунт обеспечен\nКасательно рома всё не так серьёзно, конечно, но рекомандую держать его на корабле постоянно - нет лучшего лекарства от всех хворей, как добрая кружка рому после вахты. Матросы любят и уважают капитанов, выдающих ежедневные порции рома\nТак что докупите необходимое количество, хотя бы сто пачек провианта и десять бочонков рому.";
				link.l1 = "Пожалуй, ты прав, Паскаль. Пойду снова к купцу.";
				link.l1.go = "Folke_11_1";
			}
		break;
		
		case "Folke_11_1":
			DialogExit();
			NextDiag.CurrentNode = "Folke_goods_3";
			LAi_SetStayType(npchar);
			AddQuestRecord("Sharlie", "14");
		break;
		
		case "Folke_goods_3":
			dialog.text = "Вы закончили закупку провизии и рома, капитан?";
			if (bOk)
			{
				link.l1 = "Да. Теперь мы можем смело отправляться в путь?";
				link.l1.go = "Folke_12";
			}
			else
			{
				link.l1 = "Нет, я ещё этим занимаюсь.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Folke_goods_3";
			}
		break;
		
		case "Folke_12":
			dialog.text = "Да, месье де Мор. Думаю, теперь мы можем по вашей команде попугать местных контрабандистов.";
			link.l1 = "Тогда будьте наготове, а я пока отправлюсь обратно в город.";
			link.l1.go = "Folke_13";
		break;
		
		case "Folke_13":
			dialog.text = "Не беспокойтесь, я уже отдал все необходимые распоряжения. Если понадоблюсь вам, капитан, вы всегда можете найти меня на мостике.";
			link.l1 = "...";
			link.l1.go = "Folke_14";
		break;
		
		case "Folke_14":
			DialogExit();
			LAi_SetImmortal(npchar, false);
			chrDisableReloadToLocation = true;
			LAi_SetActorType(npchar);
			//AddQuestRecord("Sharlie", "15");
			AddQuestRecord("Sharlie", "5-35");
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", -1);
			npchar.quest.OfficerPrice = 20;
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(npchar.id);
			npchar.loyality = 30;
			npchar.greeting = "Gr_Officer";
			npchar.Dialog.Filename = "Enc_Officer_dialog.c";
			npchar.quest.meeting = true;
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			//pchar.questTemp.Sharlie = "seabattle";//в Ле Франсуа
			DeleteAttribute(pchar, "NoNavyPenalty"); // штрафуем за нехватку навигации
			AddDialogExitQuest("FirstOut_6"); 
		break;



		case "Folke_6a":
			pchar.GenQuest.StoreGoods.StoreIdx = Fortfrance_STORE;
			pchar.GenQuest.StoreGoods.Starting = true; // заполняем магазин 250912
			dialog.text = "Отличный люггер, капитан. Полагаю, для контрабандистов настали чёрные дни, хе-хе.";
			link.l1 = "Очень хорошо. По крайней мере, деньги не пропали даром... Паскаль, будут Какие-нибудь советы перед тем как отправиться в путь?";
			link.l1.go = "Folke_8a";
		break;
		
		case "Folke_7a":
			dialog.text = "Да уж, этот шлюп основательно повреждён, капитан. Для перехода до Гваделупы он с большего годен, но по прибытии в Бас-Тер нужно сразу поставить его на ремонт.";
			link.l1 = "У меня не было выбора - на верфи предложили только эту посудину. Да ещё и содрали приличную сумму, а чинить её, понимаешь ли, времени у них нет... Паскаль, будут Какие-нибудь советы перед тем как отправиться в путь?";
			link.l1.go = "Folke_8a";
		break;
		
		bOk = (GetSquadronGoods(pchar, GOOD_BALLS) >= 80) && (GetSquadronGoods(pchar, GOOD_GRAPES) >= 80) && (GetSquadronGoods(pchar, GOOD_KNIPPELS) >= 80) && (GetSquadronGoods(pchar, GOOD_BOMBS) >= 80) && (GetSquadronGoods(pchar, GOOD_POWDER) >= 180);
		case "Folke_8a":
			if (bOk)
			{
				dialog.text = "Ну, боеприпасами вы запаслись достаточно, капитан. Этого арсенала нам хватит вполне, только не забывайте своевременно пополнять его.";
				link.l1 = "Конечно, это же само собой разумеется. Ещё какие-то замечания?";
				link.l1.go = "Folke_10a";
			}
			else
			{
				dialog.text = "Я осмотрел трюм, капитан. У нас недостаточно боеприпасов. Нужно как минимум по сто штук ядер, книппелей и бомб, а также сто порций картечи и пороха на двести выстрелов. Закупите необходимый арсенал, капитан - всё это не будет стоить дорого, зато спасёт наши жизни в случае нападения пиратов или испанцев.";
				link.l1 = "Хорошо. Я последую твоему совету. Отправляюсь на берег.";
				link.l1.go = "Folke_9a";
			}
		break;
		
		case "Folke_9a":
			DialogExit();
			NextDiag.CurrentNode = "Folke_goods_1a";
			LAi_SetStayType(npchar);
			AddQuestRecord("Sharlie", "12");
		break;
		
		case "Folke_goods_1a":
			dialog.text = "Вы закончили закупку амуниции, капитан?";
			if (bOk)
			{
				link.l1 = "Да, закончил. Ещё какие-то замечания?";
				link.l1.go = "Folke_10a";
			}
			else
			{
				link.l1 = "Нет, я ещё этим занимаюсь.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Folke_goods_1a";
			}
		break;
		
		bOk = (GetSquadronGoods(pchar, GOOD_WEAPON) >= 50);
		case "Folke_10a":
			if (bOk)
			{
				dialog.text = "Оружия для команды вы закупили достаточно, и правильно сделали - не дай Бог рукопашная - не голыми же руками драться. Не забывайте проверять его количество, потому что безоружный матрос - это мёртвый матрос\nИ лучше держать оружие с запасом, ибо проклятые крысы любят грызть рукояти сабель и пистолей, приводя их в негодность.";
				link.l1 = "Понятно. Вижу, ты ещё что-то хочешь сказать?";
				link.l1.go = "Folke_11a";
			}
			else
			{
				dialog.text = "У нас нехватка оружия для матросов. Не дай Бог рукопашная - что им, голыми руками драться? Безоружный матрос - это мёртвый матрос. Как я понял, у вас сорок человек экипажа\nНужно купить оружие каждому, и лучше с запасом, комплектов пятьдесят, ибо проклятые крысы любят грызть рукояти сабель и пистолей, приводя их в негодность.";
				link.l1 = "Так и поступим. Скоро вернусь.";
				link.l1.go = "Folke_10_1a";
			}
		break;
		
		case "Folke_10_1a":
			DialogExit();
			NextDiag.CurrentNode = "Folke_goods_2a";
			LAi_SetStayType(npchar);
			AddQuestRecord("Sharlie", "13");
		break;
		
		case "Folke_goods_2a":
			dialog.text = "Вы закончили закупку оружия, капитан?";
			if (bOk)
			{
				link.l1 = "Оружие в трюме. Вижу, ты ещё что-то хочешь сказать?";
				link.l1.go = "Folke_11a";
			}
			else
			{
				link.l1 = "Нет, я ещё этим занимаюсь.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Folke_goods_2a";
			}
		break;
		
		bOk = (GetSquadronGoods(pchar, GOOD_FOOD) >= 100) && (GetSquadronGoods(pchar, GOOD_RUM) >= 10);
		case "Folke_11a":
			if (bOk)
			{
				dialog.text = "Наверное, больше ничего. Провизии у нас достаточно, о роме для команды вы тоже позаботились - очень хорошо, так как нет лучшего лекарства от всех хворей, как добрая кружка рому после вахты. Матросы любят и уважают капитанов, выдающих ежедневные порции рома...";
				link.l1 = "Ну, как я понял, мы можем смело отправляться в путь?";
				link.l1.go = "Folke_12a";
			}
			else
			{
				dialog.text = "Да. Это касается провианта и рома. Если на корабле мало провианта - это плохо. Никогда не знаешь, на сколько затянется рейс - штиль или шторм могут нарушить все планы. А если закончится еда - быть беде: голодный бунт обеспечен\nКасательно рома всё не так серьёзно, конечно, но рекомандую держать его на корабле постоянно - нет лучшего лекарства от всех хворей, как добрая кружка рому после вахты. Матросы любят и уважают капитанов, выдающих ежедневные порции рома\nТак что докупите необходимое количество, хотя бы сто пачек провианта и десять бочонков рому.";
				link.l1 = "Пожалуй, ты прав, Паскаль. Пойду снова к купцу.";
				link.l1.go = "Folke_11_1a";
			}
		break;
		
		case "Folke_11_1a":
			DialogExit();
			NextDiag.CurrentNode = "Folke_goods_3a";
			LAi_SetStayType(npchar);
			AddQuestRecord("Sharlie", "14");
		break;
		
		case "Folke_goods_3a":
			dialog.text = "Вы закончили закупку провизии и рома, капитан?";
			if (bOk)
			{
				link.l1 = "Да. Теперь мы можем смело отправляться в путь?";
				link.l1.go = "Folke_12a";
			}
			else
			{
				link.l1 = "Нет, я ещё этим занимаюсь.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Folke_goods_3a";
			}
		break;
		
		case "Folke_12a":
			dialog.text = "Да, месье де Мор. Думаю, теперь мы можем по вашей команде попугать местных контрабандистов.";
			link.l1 = "Тогда будьте наготове, а я пока отправлюсь обратно в город.";
			link.l1.go = "Folke_13a";
		break;
		
		case "Folke_13a":
			dialog.text = "Не беспокойтесь, я уже отдал все необходимые распоряжения. Если понадоблюсь вам, капитан, вы всегда можете найти меня на мостике.";
			link.l1 = "...";
			link.l1.go = "Folke_14a";
		break;
		
		case "Folke_14a":
			DialogExit();
			LAi_SetImmortal(npchar, false);
			chrDisableReloadToLocation = true;
			LAi_SetActorType(npchar);
			//AddQuestRecord("Sharlie", "15");
			AddQuestRecord("Sharlie", "5-35");
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", -1);
			npchar.quest.OfficerPrice = 20;
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(npchar.id);
			npchar.loyality = 30;
			npchar.greeting = "Gr_Officer";
			npchar.Dialog.Filename = "Enc_Officer_dialog.c";
			npchar.quest.meeting = true;
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			//pchar.questTemp.Sharlie = "seabattle";//в Ле Франсуа
			DeleteAttribute(pchar, "NoNavyPenalty"); // штрафуем за нехватку навигации
			AddCharacterExpToSkill(pchar, "COMMERCE", 50);
			AddDialogExitQuest("FirstOut_7"); 
		break;
		
		
	case "dialog2":
    dialog.text = "";
    link.l1 = "";
    link.l1.go = "dialog3";
    break;  		
		
		
		
	case "dialog3":
    dialog.text = "";
    link.l1 = "";
    link.l1.go = "dialog4";
	link.l2 = "";
	link.l2.go = "dialogexit";
    break;  	



	case "dialog4":
    dialog.text = "";
    link.l1 = "";
    link.l1.go = "dialog5";
    break;  	
		
	

    case "dialog5":
	AddDialogExitQuest("MyQuest");
    dialog.text = "Тогда буду ждать вас в местной таверне.";
    link.l1 = "До скорой встречи.";
    link.l1.go = "exit";
    break;


    case "exit":
    NextDiag.CurrentNode = "Second Time";
	dialogexit();
    break;



    case "dialogexit":
    NextDiag.CurrentNode = "Second Time2";
	dialogexit();
    break;




    case "Second Time":
    dialog.text = "Капитан, вы уже выполнили мою просьбу?";
    link.l1 = "Немного терпения, сударь.";
    link.l1.go = "exit";
    break;



    case "Second Time2":
    dialog.text = "Ваш отказ достоин сожаления.";
    link.l1 = "Держитесь от меня подальше, сударь.";
    link.l1.go = "dialogexit";
    break;
	
	
	
	case "complete":
    dialog.text = "Капитан, вы уже выполнили мою просьбу?";
    link.l1 = "Господин, о котором вы мне говорили, напал на меня. Мне пришлось защищаться. На его трупе я нашёл алмаз. Держите, мне он не нужен.";
    link.l1.go = "complete1";
    break;
	
	
	
	case "complete1":
	AddQuestRecord("MyQuest", "4");
	CloseQuestHeader("MyQuest");
	log_info("вы отдали алмаз");
	TakeItemFromCharacter(pchar, "jewelry2");
	AddMoneyToCharacter(pchar, 10000);
    dialog.text = "Да, я вас понял. Стечение обстоятельств и только, хе-хе. Возьму этот камень на память. Но я не могу его взять просто так, вот ваша компенсация.";
    link.l1 = "Не знаешь, где найдёшь, а где потеряешь. Всего доброго.";
    link.l1.go = "exitcomplete";
    break;
	
	
	
	case "exitcomplete":
	NextDiag.CurrentNode = "Three Time";
	dialogexit();
    break;
	
	
	case "Three Time":
    dialog.text = "Здравствуйте, сударь. Мы разве знакомы?";
    link.l1 = "Нет, просто хотел выразить вам своё почтение.";
    link.l1.go = "exitcomplete";
    break;





	
		
		}
}