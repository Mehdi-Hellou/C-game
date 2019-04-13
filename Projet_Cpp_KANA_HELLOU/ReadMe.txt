&&&&&&&=================================================&&&&&&&
      	      		      READ ME
&&&&&&&=================================================&&&&&&&

===============================================================
			       LORE
===============================================================

Vous vous trouvez contraint de vous incarner en un être dans un 
univers parallèle. Au sein de la forêt dans laquelle vous vous 
réveillez, des ennemis rôdent. Après avoir vaincu les différents 
méchants, vous devrez affronter l'ultime boss, à vous de le
découvrir

===============================================================
			     CONTROLES
===============================================================
Les touches sont configurées pour un clavier AZERTY

------------------------------  J1  ---------------------------
Aller à droite : RIGHT ARROW KEY
Aller à gauche : LEFT ARROW KEY
Attaque CaC de zone : LEFT SHIFT 
Attaque à distance : N

------------------------------  J2  ---------------------------
Aller à droite : D
Aller à gauche : Q
Attaque CaC de zone : E
Attaque à distance : A

===============================================================
			PRINCIPE DU PROGRAMME
===============================================================

Le premier joueur sélectionne combien de joueurs vont jouer lors
de la partie.

Il sélectionne ensuite son personnage, et le second personnage 
sera attribué à l'éventuel second joueur.

La partie se charge, et prend un peu de temps.

Chaque personnage comprend ses textures et ses attaques en tant
qu'objet. Les ANIMATIONS sont un point important du programme.
Tout comme les fonctions gérant les différents sens et interac-
tions du personnage à chaque appui de touche.

Chaque attaque comprend une detection de collision et tous les
sprites comprennent des animations en fonction du temps d'appui
ou non de la touche correspondante.

Chaque 10 secondes (modifiables), une vague de monstre apparaît.
Le nombre de vague et d'ennemi est modifiable mais actuellement:

Vague 1 : 1 ennemi
Vague 2 : 2 ennemis
Vague 3 : 3 ennemis
Vague 4 : Boss

===============================================================
			   AMELIORATIONS
===============================================================

  -  Charger toutes les textures dans la partie et les copier
dans chaque objet Personnage présent dans la partie; cela acc-
élererait le chargement du jeu.
  -  Ajouter des vague de Boss successives.
  -  Ajouter une carte que l'on peut défiler à droite.
  -  Ajouter d'autres classes de Personnage
  -  Ajouter des niveaux avec l'expérience
  -  Ajouter un inventaire et des objets ainsi qu'augmenter les
stats au fil du jeu
  -  Ajouter du son
  -  Mieux gérer les temps d'animation pour être précis

===============================================================
		        INSTALLATION DE SDL
===============================================================

Entrez les lignes de code suivantes dans un terminal:

*  apt-cache search libsdl2: pour chercher le paquet
*  sudo apt-get install libsdl2-dev libsdl-image2-dev 
    libsdl-ttf2.0-dev: installe les librairies


===============================================================
		           COMPILATION
===============================================================

Ajouter en include : -I/usr/include/SDL2 (par défaut)
Ajouter en librairie : -lSDL2_image -lSDL2main -lSDL2 

===============================================================
		           ORGANISATION
===============================================================

Au début, on a commencé à voir ensemble le concept du jeu ainsi
que l'UML et les différentes classes.
Au fil du temps, on apportait chacun des idées d'avancée ou de
modification.
Nous nous attribuions différentes parties de classes comme
celles des personnages puis on fusionnait et on adaptait les
bouts de code afin que tout marche bien.
Vers la fin, Mehdi s'est concentré sur les personnage et leurs
différentes interactions et animations tandis que Jean-Louis 
s'est plutôt concentré sur les menus, les contrôles et l'inter-
face.

===============================================================
			     CREDITS
===============================================================

Objet : Projet C++
Titre : Forest SurvivoRob
Auteurs : Mehdi HELLOU - Jean-Louis KANA / ROB 4 - 2017/2018

                                                                            `----.`                                                                                        
                                       `.---.`                                                         `/sso+///-`                                                                                      
                                      -ooo/::::.                                                      `+yyys+:-://                                                                                      
                                     :yyys+:.`-:-                                                     :yddhyso/:+o.                                                                                     
                                    `ohdhyso/::/+`                                                    -hmmmdhys+oo`                                                                                     
                                    `sdNmdhyssoo+`                                                     /hddhs+-/+-                                                                                      
                                     -ydmdyo::+o.                                                       .osyo/`-/                                                                                       
                                      `+hhs+.`.-                                                        `:+ys/`./`                                                                                      
                                       /hhso-`.:.                     ````...----.---.......````        ./+ys+.`:.                                                                                      
                                       :yhyo:`.:/.          ``..-::////++++++++++yo++++++++++///::-.`` `://ys+-`:-                                                                                      
                                       -yhyo/`.://-    ``-:++ooooooooo++///:::///ys:::::::----::::::::-:///syo:`::                                                                                      
                                       .shys/..-///:---/ssyyysssssssooo++////::::oy--+:--.````...---::::://syo:`-:                                                                                      
                                       `ohys+..-/++oyysyyyyyyyyysssssooo++shy/:-:/h-/ds/:``````..---::::://oys/`./                                                                                      
                                       `+hhs+-.:oshdhyyyyyhhyyyyysssssoo++oyys/:::h:-/+:.``````...--::::://+hs+../`                                                                                     
                                        /hhyo:/shdmdyyyyyyyyyyyyyyyyyyysssssssooo+so+++++++////////////////+hy+.`:.                                                                                     
                                        :yhyyosmmmmhyyyhhhhdddddddhhyysoo+++++//:-/o::::--.....--::///++++o+yyo-`:-                                                                                     
                                        -ydhhhmNmNmyyhdmmdddhyyyssssooo++//+yo::-.:y:oh+-:```````..---::::/oyyo:`-:                                                                                     
                                        .yddddmNNNmmmdhhyyyyyyyyssssssoo+++sddy+--:h:/hyo-````````..-:::::://++/.-/                                                                                     
                                        `sdddddmmmdhyyyyyyhhhyyyysssssoo++/////::-:y+-.....````...--:////::///:////:-.                                                                                  
                                        `oyyhhhhhhdhyyyyyhhhhyyyyssssoo+++///:::::::--.....```...--::////::://:::::::::`                                                                                
                                      `.+sssssyyyhddhhhhyyyyyyyyssssssoo+++++//////:::------..------::::::::://-.----::-..`                                                                             
                                      -:ssssssssyyddhhhyyyyyyyyyyyyyhhhhddddddmmmmmmmmmmNNmmmNNmmmmmmdh+::-:://-`````.-::::`                                                                            
                                   `/oy+ssssoosssyddhhyyyydyyyysdNNNMMMMMMMMMMMNNNNNNNNNMMMMMMMMMMMMMMMd---:/://``````.-..--                                                                            
                                  -+yyhdhysssssyyhddhhyhhhdyyyy+mMMMMMMMMMMNMMNNNNmddmNmhmdydNMMMMMMMMMN:---:://:......--`.:                                                                            
                                  :+yyhddhyyssyyhdmdhhhhhhmyyys+dMMMMMMNNmmddmhyydNydNso+s:-+ohmMMMMMMMMo.--::///::///::////`                                                                           
                                  :+hhdmmdhyyyhhdmmdhhhhhhmhyysohMMNNMNmmdd+:shsoomNNd+/ss/:oyhmMMMMMMMMh.--:::///+++++/+ooo`                                                                           
                                  :+hdmmmdddhdddmmmhhyhhhhdhyysssMNNmNNdhhhhhhhhddNNmNhhyoooss+smMMMMMMMh.---::///+oooo+oyyo`                                                                           
                                  -+dmNNNmmmmmmmmmmhhhhhhhdyyyyyommdhdhsooooo+///:+/:/:----....``````.....---/:://+ssssoyhh/                                                                            
                                  .+mNNNNmNNmNNNmmdhhhhhhhdyhyyyssssoooo+++///:::::------....````````````.-:+:::///syyyyso:                                                                             
                                   omNNNNmNNNNNNmdyyyyyhhhddddhyyyyssyyyyyyyhhhhhddddmmmmmmmmdddddddhhhhyys+/:::://+hhhy`                                                                               
                                   `/oydhNNNNNNNhsssyyhhhddmmNNNNNNNNNNNNNNmmmddhhhyyysssooo+++///::::-----::::::///sso.                                                                                
                                       -yNNNNMNhsssyyyhhhddmmmmmmmmmmmmmmmmmmmmmmmmNNmmmmmmmmmddddddmmmmh..--:::::///.                                                                                  
                                        -oydNNmssssyyyyhhdddddhhhohNNNNNNNmmmddhhyysoo++//::--......--oNN+`.--::::://-                                                                                  
                                          `/dNhoossyyyyhhhhhhyyys/oydhhhyyssoo++//::::---...``````````.hNy`.--::::://:`                                                                                 
                                           :dms/ossyyyyhhhhyyyyss//:ssssoo+++///::::::::-------........+h+`..--::::://:-`                                                                               
                                           :dm+:ossyyyyyyhhyyyysso/+ooooooo++++++/////:::----....```````````..--::::///-/`                                                                              
                                         .ohdd/:ossyyyyyyyyyyyssssssssssssssssssssssssssssssssssoooooooooooo++++++//////+`                                                                              
                                        `sdmmm/:ossyyyyyhhhhhhhhhhddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddhhysoo-                                                                               
                                        `ymNNd//osyhhddmmNNNNNNNNNNNNNNNNNNNMMNNNNNNNmmmmmmmmdmmmmmmmmmNNMMMMNNNNmmmmddy-                                                                               
                                         .+ydy+shdmNNNNNNNMNMNNNNMMMMMMMMMMMMNNNNNNNmmmmmmdddddddddmmNNMMMMMMMMMMNNmmmh:                                                                                
                                           `/ydmNNNNNNMMMMMMMNNNNNMMMNNNNNmmddhhhhhhdddddddddhdddddNMMMMMMMMMMMMMNmmds.                                                                                 
                                           `odmNNNNNMMMMMMMMMMMNNNNNNmmddhyso+::///++ossosssyyyhhhhmmNNNNNMMMMMNNmds-                                                                                   
                                           .dmmNmdhhhhhhhhhhhddmmmmddhhyyssso/--://ymmmNmho+++oooosssssyyyyyhhdds/.                                                                                     
                                           `ody+//osyssssssooooossyyyyysssoso+-.//hNmhhdhdNh+++++++ohhhdhhhhyyso/-                                                                                      
                                           ``--+syyyyssooo++++++++oooshyysoso+-./+Nhhhhhhhmmh++++++omshs+ohhssyhhs-                                                                                     
                                         `-+yhddmmmmmddhdddhhyyyyso+++shhhsso+--/oN+yyydhhhhms/////odhdd++mhh/odhdo.                                                                                    
                                        :ydmmmmmmmddhssossyyhhdddmmddhhdhhyss+--/+N--/-yoos/sd/////+d+yy//oyo/+ddod/`                                                                                   
                                       -dmmmmdhhhhys+/:---://+osyhdmNNMmdhhys+.://yh...md-..od//////d+hhs//////++/ho-                                                                                   
                                       `+hmhooshhyys+//:::///////+oyNMMmhhhyo/.////hy-.dm/.-md++o+//yyhhd/++////+sod/.                                                                                  
                                         ./+:+yyyyso/:-.--::///+++oodMMmhhhyo/./////yds+//omdymmdyh++dyy++dho///yhmm//:`                                                                                
                                          `-/oyhhyys+/:::-:::////++omMMdhhhyo/.//////+shNdho//ydho+d//+shsddy///+yyys//:.                                                                               
                                          -//+yyyyso/:-.--:///++++oohMNhhhhso/-////////+Ns////+dhhhm+////yy+///////oh////.                                                                              
                                          `:/shhyysoo+/:::://////++odNdhhhyso/-///////omdyh+///+hdds//////yyohy//oy+m/////-                                                                             
                                          ::/oyyysso//:----:////++++oyhhhhhso:-///////hhy/oh///////////////dydm+/dydm//////-                                                                            
                                          --/osyyss/--.....-:::://///+ydhyyso:-///////odhhhd///////////////odhy++ohyd+//////-                                                                           
                                        ``-osyyysso:--.....-:::://///odmdyyso::////////ohdddho////+hy///////+osyyhhyy+///////.                                                                          
                                       ` ./syyyyss+:--....-:::://///+smmdyss+:://///oy/////dyd////odds////ydy/////////////////.                                                                         
                                      ```-osyyysss/---....-::::///++oymddhss+-://///Nsd/////o+/////os+////ydm//////////////////-                                                                        
                                      ` ./osyyysso/---....-:::///+++odmddhss+-//////ohs/oyhdmmmNNmmmmdhhyso+/////omh///////:///::.                                                                      
                                     ```-osyyyysso/---....-:::///+++smmddhss+-////////+NNyo/-..````..-:/+sydmmhs/+dm+/////+:.-:://:-`                                                                   
                                     ``.+osyyyyyyyo+/:-.`.-::///+++oymmddhso+-////////Nms/:-..`````````````..:+hNy//////////::--::///:-`   `-://+///:-.`                                                
                                    ``.+yhmmmmmmdddhhhhhdyo+/://+++sdmmddhso/-///hh+/dNys/:-..-:::::--..```...-:omd////////+/:::--::////::oyyyyyyyyyyysso/-`                                            
                                    `/hddhyyhhhyyso:--...-/shhyo+ooymmmddhso/-//+mhhoMhyy+:--hmhyyyyyhhdddho-.-:+ydd///////oso+/::::-:/+shyyyydmmmmmNNNmdyss+-                                          
                                   `ydmhooosyhyyyys+//::-...-/ohdysymmddhhso/-///+s/dNhddhysdd-.```````...:+d+-:+yymd/dhy//+yysoo+//:/+hmdhyyymmmmmNMMMMMMNdys+`                                        
                                   :mmy/:+shddddhhso+/////+ossssymddmmddhhso/://////MMMNdhsoo:.`````````````-dhhhdhymyyhh///hhhyssossyNMNNdhssydmmNNMMMMMMMMMmy+                                        
                                   `hm++yhyyyhhyys+:-.````.-:+oyddNmmmddhhso:://///+MMMhyo/--./osssssoo+/:-..-/+sdmNNMo/////smddhyyymMMMNNNmdyssyhdmNMMMMMMMMMNo                                        
                                    .sydy++osyyyys+:-.````.-:/+oymNNmmddhhso:://++/sMMmyys/:-sms+////++ossyhh/.-:oydMMd//////dmmdddmMMMMNNNmmNmdhyysshmMMMMMMMm-                                        
                                     `/h::/ooyyyys+:-..```.-:/+oyNNmmdddhys+::/+mysyMMmmmmmddm/.```````````./do:/oyymMMo/////ymmmmNMMMMNNNNmmmmNmmmdhyymMMMMMN+                                         
                                       --:/oshhhhhhhhyyyso+++++osNNmmdddhyso:///hhshMMMMdhy+/:.......```````.-hhdmmddNMd/sy+/+dmmmMMMMmmNNNmmNNmmmmmmmddNNNNNy`                                         
                                       `-+yhdmNNNNNNNmmddmmmmmdyymNmmdddhyso/////+/yMMMmyys/:-:hddhhhhhhyyso/--:/shdMMMM+dhh//yddmNNMddNNNNNmNNmmmmmmmdNNNNms.                                          
                                       .ydmmNNNmmmhs+/-.-/shmNNNmmNmmddddhso///////sNNNhyyyo:/mms/--.----:+sdm+-:oyydMMMy+s+//:-/syhmymNNNNNNmmmmmmmmddmdy+.                                            
                                       .hmmNmhsyhys/-.``.-/oyNNNmmmmmddddddhsooooo+oooooooo+/oso+/:----...-:oyd+:oyyymMMm//////`  `-hdNNNNNNNNmmmmmmdo..`                                               
                                        .ohdo/oshys/-.` `-/++dmdmmmmmmmNmmmdy+/////++++++++++oooooooooooo++++ooo++oooosss//////`    /dNNNNNNmmmNNmmy:`                                                  
                                          .+y++syyo/-...-:/+/-sdmddmmmdddddhy+//yy+////////+o/////////////////////++++++++oooo/`     .odmNNmmNmdy+-`                                                    
                                         -//o+///:/osso/:::::::/oyyhhhhhddddyo/+msd////////dyh////////hys////////ys////////++/:        `-/+++/-.                                                        
                                ```....-::-------+dNNmNmo-------:/+o++/:/hddho//oys////////yyh////////hyh///////odho///////dyy/`                                                                        
                               `/:--------------:hNNNmmNd+:----//ooo:/o/.ohddy+++/+///////////////////+o+////////sy+///////syy/.                                                                        
                               -o-------------/shmMNNmmNmdhs:-+:-:-+/--s-ommmdhhhhyyyyyyssssssooooooo++++++++++////////////////.                                                                        
                               -o------------odmmNmhyyhdmmmmd+o/--/:s-:o-+mmmmmmmmmmmmmmmmmmmmmmmdhhhhddddddddhhhhhhyyyyyssoo+/.                                                                        
                               -o----------.odmNNdyyhhdmddmmmh/++/+oo//:.osooooossssssssssyyyyyydyssssydhhdNmddddddmmmmNNh+-.`                                                                          
                               -o-----------hdmdo.:+ooshhydddd/--://:---:shs////////////+++++++++o+/+++ys+++++++++ooooosyso:`                                                                           
                               .s+----------yd+`      -ysssyyy:---------oyyho:////////////////////+/////ys///////////////////.                                                                          
                               `syo--------./:       .ssssssy+--------:syyyhh/:////////////////////+////+dhssso++++++//++++///:---``                                                                    
                                +yyo:--------.       ossssssy+-------:syhyyyhs://+//////////////////////+hmhhhhhyyso+///////////////::-.``                                                              
                                -yhhs:-------:      -ssssssyy+------/yhhyyyyyy//ydd///////////sdh///o/+++yNdhhhhhhhhhyo//////////////////:-.`                                                           
                                 -yhhho------/      +ssssssyyo----:ohhhyyyyyyy+/sdd///////////shm+++o++++sNdhhhhhhhhhhhys////////////////////-.......--------`                                          
                                  .yhhhy/----/     `sssssssyys:--/yhhhyyyyyyyy++/++++++++++++++oo+++o++ooyNdhhhhhhhhhhhhhyo////////+ss+////////////////:::::::-`                                        
                                   .shhhhs++oo     -yssssssssddyyyhhhyyyysssys+++++++++++++++++++++osoooshNdhhhhhhhhhhhhhhhy+////+shhhho/////+/://///s+//:::oyo:.                                       
                                    `+hhhddmds     +sssssssssdNmdhhhysysssssyo+++++++++++++++oooooosooosymmhhhhhhhhhhhhhhhhhho++shhdhhhhy///yNyo////+myh+:::+dyh/-                                      
                                      .shddmms    `ssssssssssdNmdhyysssssssyso++ooooooooooooooooossssssyhNdhhhhhhhhhhhhhhhhhhhyhddddddddhh+//shNo/:///ydh/:::/sh+::`                                    
                                        :ymmh:    -ysssssssssyddhysssssssssyooshNsoooooooosssdmyssyssyyhNmhhhhhhhhhhhhhhhhhhhhddddddddddhhhs//://:///::::/:::::::://-                                   
                                          ``      /ssssssssssssssssssssssyyssyNhhsssssssssssNddyyhyyhhdNmdddddddddhhhhhhhhddddddddhddddddhhdy+/++++++oooooossssssss+`                                   
                                                 `ossssssssssssssssssssshyyyyyyyyyyyyyyyyyyyhhhhdhddmmNmddddddddddhhhhhhhhhhhhhhhhhddddddhddhyyyyyyyyyyyyyyyyyyyyo.                                     
                                                 `ssssssssssssssssssssyyyyyyyyyyyyyyyyyyyyyhhhddmmNNNNmdddddddddhhhhhhhhhhhhhhhhhhhdddddddhyyyyhhhhhhhdddddmdyys:                                       
                                                 `sssssssssssssssssssyo+++++++ooooooooooooooosdmNNNNmmddddhhhhhhhhhhhhhhhhhhhhhhhhhdddddhyyhmNNNNNNNNNNNNNNdys/`                                        
                                                 -sssssssssssssssssssy+//sdy++++odmoo+oodmoooo/+syhhhhhhhhhdhhhhhhhhhhhhhhhhhhhhhhhhhdhyyymNNNNNNNNNNNNNNmyso-                                          
                                                `ossssssssssssssssssss+/+dyd++++ydmso++hdmooo+    `````````-+ydhhhhhhhhhhhhhhhhhhhhhhhysyNNNNNNNNNNNNNNmdss+`                                           
                                               `/sssssssssssssssssssso///yy+++++ohy++++shyooo:               `:yhhhhhhhhhhhhhhhhhhhhhsshNMNNNNNNNmmmmmmhss:`                                            
                                              `/ssssssssssssssssssssy+//+++++++++++++++++oooo.                 `+hhhhhhhhhhhhhhhddhysshmNNMNMMNNNmmmmdyso-                                              
                                              /ssssssssssssssssssssss+++++++++++++++++++++oo/                    :hhhhhhhhhhhddddhyssyhddddmmNNNNmmmhss+`                                               
                                             :sssssssssssssssssssssyo++++++++++++++++ooooooo.                     -hhhhhhhhhhhhhyssssssssssyyhdmmmdyss:`                                                
                                            :sssssssssssssssssssssyso++++++oooooooooooooooo/                       -hhhhhhhhhhhyssooooooooooooosyhyso.                                                  
                                           -sssssssssssssssssssssssoooooooooooooooosssssss+`                        .yhhhhhhhhyssoooooooooooooossss/`                                                   
                                          `osssssssssssssssssssssyssssssyyyyyyyyyyyyyyhhh+`                          `ohhhhhysssssssssssssssssssso-                                                     
                                          /ssssssssssssssssssssyhhhhyyyyyyyyysssssssooooo////:.                       `/yhhyssssssssoooo+++///::-`                                                      
                                         .ssssssssssssssssssssssssssso/////////////////////+++/                         .+/::---...`````                                                                
                                         /ssssssssssssssssssssssssssss/////////////////////////                                                                                                         
                                        `ossssssssssssssssssssssssssss/////////////////////////                                                                                                         
                                        -sssssssssssssssssssssssssssss/::://://///+o////:/syo//                                                                                                         
                                        :sssssssssssssssssssssssssssss::/syy/::::+dyh:///+dsh/:                                                                                                         
                                        /sssssssssssssssssssssssssssso::/hsh/::::/hys::::/yy+/:                                                                                                         
                                        +sssssssssssssssssssssssssssso:::+o/:::::://:::://////:                                                                                                         
                                        -/++++ooooosssssssssssssssssyo::::::::::::::::::::----`                                                                                                         
                                                  ``````.....---::::/:.......`````                                                                                                                      
                                                                                              
