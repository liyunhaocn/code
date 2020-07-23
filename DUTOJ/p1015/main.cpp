#include <iostream>

using namespace std;

class Solution {
public:
    bool isnum(int n){
    int a[10]={0};
        while(n){
            int ge = n%10;
            a[ge]++;
            if(a[ge]>1){
                return true;
            }
            n/=10;
        }
        return false;
    }

    int numDupDigitsAtMostN(int N) {
        int ret[1001]={0, 831430, 1770950, 2710470, 3649990, 4589510, 5529030, 6468550, 7408070, 8347590, 9287110, 10266950, 11266950, 12246790, 13226630, 14206470, 15186310, 16166150, 17145990, 18125830, 19105670, 20085510, 21065350, 22065350, 23045190, 24025030, 25004870, 25984710, 26964550, 27944390, 28924230, 29904070, 30883910, 31863750, 32863750, 33843590, 34823430, 35803270, 36783110, 37762950, 38742790, 39722630, 40702470, 41682310, 42662150, 43662150, 44641990, 45621830, 46601670, 47581510, 48561350, 49541190, 50521030, 51500870, 52480710, 53460550, 54460550, 55440390, 56420230, 57400070, 58379910, 59359750, 60339590, 61319430, 62299270, 63279110, 64258950, 65258950, 66238790, 67218630, 68198470, 69178310, 70158150, 71137990, 72117830, 73097670, 74077510, 75057350, 76057350, 77037190, 78017030, 78996870, 79976710, 80956550, 81936390, 82916230, 83896070, 84875910, 85855750, 86855750, 87835590, 88815430, 89795270, 90775110, 91754950, 92734790, 93714630, 94694470, 95674310, 96654150, 97654150, 98654150, 99654150, 100649110, 101644070, 102639030, 103633990, 104628950, 105623910, 106618870, 107613830, 108613830, 109613830, 110613830, 111613830, 112613830, 113613830, 114613830, 115613830, 116613830, 117613830, 118608790, 119608790, 120608790, 121603750, 122598710, 123593670, 124588630, 125583590, 126578550, 127573510, 128568470, 129568470, 130563430, 131563430, 132558390, 133553350, 134548310, 135543270, 136538230, 137533190, 138528150, 139528150, 140523110, 141518070, 142518070, 143513030, 144507990, 145502950, 146497910, 147492870, 148487830, 149487830, 150482790, 151477750, 152472710, 153472710, 154467670, 155462630, 156457590, 157452550, 158447510, 159447510, 160442470, 161437430, 162432390, 163427350, 164427350, 165422310, 166417270, 167412230, 168407190, 169407190, 170402150, 171397110, 172392070, 173387030, 174381990, 175381990, 176376950, 177371910, 178366870, 179366870, 180361830, 181356790, 182351750, 183346710, 184341670, 185336630, 186336630, 187331590, 188326550, 189326550, 190321510, 191316470, 192311430, 193306390, 194301350, 195296310, 196291270, 197291270, 198291270, 199286230, 200286230, 201281190, 202276150, 203271110, 204266070, 205261030, 206255990, 207250950, 208245910, 209245910, 210245910, 211240870, 212235830, 213230790, 214225750, 215220710, 216215670, 217210630, 218210630, 219210630, 220210630, 221210630, 222210630, 223210630, 224210630, 225210630, 226210630, 227210630, 228205590, 229200550, 230200550, 231200550, 232195510, 233190470, 234185430, 235180390, 236175350, 237170310, 238165270, 239160230, 240160230, 241155190, 242155190, 243150150, 244145110, 245140070, 246135030, 247129990, 248124950, 249119910, 250119910, 251114870, 252109830, 253109830, 254104790, 255099750, 256094710, 257089670, 258084630, 259079590, 260079590, 261074550, 262069510, 263064470, 264064470, 265059430, 266054390, 267049350, 268044310, 269039270, 270039270, 271034230, 272029190, 273024150, 274019110, 275019110, 276014070, 277009030, 278003990, 278998950, 279998950, 280993910, 281988870, 282983830, 283978790, 284973750, 285973750, 286968710, 287963670, 288958630, 289958630, 290953590, 291948550, 292943510, 293938470, 294933430, 295928390, 296928390, 297928390, 298923350, 299918310, 300918310, 301913270, 302908230, 303903190, 304898150, 305893110, 306888070, 307883030, 308883030, 309877990, 310877990, 311872950, 312867910, 313862870, 314857830, 315852790, 316847750, 317842710, 318837670, 319837670, 320837670, 321832630, 322827590, 323822550, 324817510, 325812470, 326807430, 327807430, 328807430, 329807430, 330807430, 331807430, 332807430, 333807430, 334807430, 335807430, 336807430, 337802390, 338797350, 339792310, 340792310, 341792310, 342787270, 343782230, 344777190, 345772150, 346767110, 347762070, 348757030, 349751990, 350751990, 351746950, 352746950, 353741910, 354736870, 355731830, 356726790, 357721750, 358716710, 359711670, 360711670, 361706630, 362701590, 363701590, 364696550, 365691510, 366686470, 367681430, 368676390, 369671350, 370671350, 371666310, 372661270, 373656230, 374656230, 375651190, 376646150, 377641110, 378636070, 379631030, 380631030, 381625990, 382620950, 383615910, 384610870, 385610870, 386605830, 387600790, 388595750, 389590710, 390590710, 391585670, 392580630, 393575590, 394570550, 395565510, 396565510, 397565510, 398560470, 399555430, 400550390, 401550390, 402545350, 403540310, 404535270, 405530230, 406525190, 407520150, 408520150, 409515110, 410510070, 411510070, 412505030, 413499990, 414494950, 415489910, 416484870, 417479830, 418474790, 419474790, 420469750, 421469750, 422464710, 423459670, 424454630, 425449590, 426444550, 427439510, 428434470, 429429430, 430429430, 431429430, 432424390, 433419350, 434414310, 435409270, 436404230, 437404230, 438404230, 439404230, 440404230, 441404230, 442404230, 443404230, 444404230, 445404230, 446404230, 447399190, 448394150, 449389110, 450384070, 451384070, 452384070, 453379030, 454373990, 455368950, 456363910, 457358870, 458353830, 459348790, 460343750, 461343750, 462338710, 463338710, 464333670, 465328630, 466323590, 467318550, 468313510, 469308470, 470303430, 471303430, 472298390, 473293350, 474293350, 475288310, 476283270, 477278230, 478273190, 479268150, 480263110, 481263110, 482258070, 483253030, 484247990, 485247990, 486242950, 487237910, 488232870, 489227830, 490222790, 491222790, 492217750, 493212710, 494207670, 495202630, 496202630, 497202630, 498197590, 499192550, 500187510, 501182470, 502182470, 503177430, 504172390, 505167350, 506162310, 507157270, 508157270, 509152230, 510147190, 511142150, 512142150, 513137110, 514132070, 515127030, 516121990, 517116950, 518111910, 519111910, 520106870, 521101830, 522101830, 523096790, 524091750, 525086710, 526081670, 527076630, 528071590, 529066550, 530066550, 531061510, 532061510, 533056470, 534051430, 535046390, 536041350, 537036310, 538031270, 539026230, 540021190, 541021190, 542021190, 543016150, 544011110, 545006070, 546001030, 547001030, 548001030, 549001030, 550001030, 551001030, 552001030, 553001030, 554001030, 555001030, 556001030, 556995990, 557990950, 558985910, 559980870, 560975830, 561975830, 562975830, 563970790, 564965750, 565960710, 566955670, 567950630, 568945590, 569940550, 570935510, 571935510, 572930470, 573930470, 574925430, 575920390, 576915350, 577910310, 578905270, 579900230, 580895190, 581895190, 582890150, 583885110, 584885110, 585880070, 586875030, 587869990, 588864950, 589859910, 590854870, 591854870, 592849830, 593844790, 594839750, 595839750, 596839750, 597834710, 598829670, 599824630, 600819590, 601814550, 602814550, 603809510, 604804470, 605799430, 606794390, 607794390, 608789350, 609784310, 610779270, 611774230, 612774230, 613769190, 614764150, 615759110, 616754070, 617749030, 618749030, 619743990, 620738950, 621733910, 622733910, 623728870, 624723830, 625718790, 626713750, 627708710, 628703670, 629703670, 630698630, 631693590, 632693590, 633688550, 634683510, 635678470, 636673430, 637668390, 638663350, 639658310, 640658310, 641653270, 642653270, 643648230, 644643190, 645638150, 646633110, 647628070, 648623030, 649617990, 650612950, 651612950, 652612950, 653607910, 654602870, 655597830, 656597830, 657597830, 658597830, 659597830, 660597830, 661597830, 662597830, 663597830, 664597830, 665597830, 666592790, 667587750, 668582710, 669577670, 670572630, 671567590, 672567590, 673567590, 674562550, 675557510, 676552470, 677547430, 678542390, 679537350, 680532310, 681527270, 682527270, 683522230, 684522230, 685517190, 686512150, 687507110, 688502070, 689497030, 690491990, 691486950, 692486950, 693481910, 694476870, 695476870, 696476870, 697471830, 698466790, 699461750, 700456710, 701451670, 702446630, 703446630, 704441590, 705436550, 706431510, 707431510, 708426470, 709421430, 710416390, 711411350, 712406310, 713406310, 714401270, 715396230, 716391190, 717386150, 718386150, 719381110, 720376070, 721371030, 722365990, 723365990, 724360950, 725355910, 726350870, 727345830, 728340790, 729340790, 730335750, 731330710, 732325670, 733325670, 734320630, 735315590, 736310550, 737305510, 738300470, 739295430, 740295430, 741290390, 742285350, 743285350, 744280310, 745275270, 746270230, 747265190, 748260150, 749255110, 750250070, 751250070, 752245030, 753245030, 754239990, 755234950, 756229910, 757224870, 758219830, 759214790, 760209750, 761204710, 762204710, 763204710, 764199670, 765194630, 766194630, 767194630, 768194630, 769194630, 770194630, 771194630, 772194630, 773194630, 774194630, 775194630, 776189590, 777184550, 778179510, 779174470, 780169430, 781164390, 782159350, 783159350, 784159350, 785154310, 786149270, 787144230, 788139190, 789134150, 790129110, 791124070, 792119030, 793119030, 794113990, 795113990, 796113990, 797108950, 798103910, 799098870, 800093830, 801088790, 802083750, 803078710, 804078710, 805073670, 806068630, 807068630, 808063590, 809058550, 810053510, 811048470, 812043430, 813038390, 814038390, 815033350, 816028310, 817023270, 818023270, 819018230, 820013190, 821008150, 822003110, 822998070, 823998070, 824993030, 825987990, 826982950, 827977910, 828977910, 829972870, 830967830, 831962790, 832957750, 833957750, 834952710, 835947670, 836942630, 837937590, 838932550, 839932550, 840927510, 841922470, 842917430, 843917430, 844912390, 845907350, 846902310, 847897270, 848892230, 849887190, 850887190, 851882150, 852877110, 853877110, 854872070, 855867030, 856861990, 857856950, 858851910, 859846870, 860841830, 861841830, 862836790, 863836790, 864831750, 865826710, 866821670, 867816630, 868811590, 869806550, 870801510, 871796470, 872796470, 873796470, 874791430, 875791430, 876791430, 877791430, 878791430, 879791430, 880791430, 881791430, 882791430, 883791430, 884791430, 885786390, 886781350, 887776310, 888771270, 889766230, 890761190, 891756150, 892751110, 893751110, 894751110, 895751110, 896746070, 897741030, 898735990, 899730950, 900725910, 901720870, 902715830, 903710790, 904710790, 905705750, 906705750, 907700710, 908695670, 909690630, 910685590, 911680550, 912675510, 913670470, 914670470, 915665430, 916660390, 917660390, 918655350, 919650310, 920645270, 921640230, 922635190, 923630150, 924630150, 925625110, 926620070, 927615030, 928615030, 929609990, 930604950, 931599910, 932594870, 933589830, 934589830, 935584790, 936579750, 937574710, 938569670, 939569670, 940564630, 941559590, 942554550, 943549510, 944549510, 945544470, 946539430, 947534390, 948529350, 949524310, 950524310, 951519270, 952514230, 953509190, 954509190, 955504150, 956499110, 957494070, 958489030, 959483990, 960478950, 961478950, 962473910, 963468870, 964468870, 965463830, 966458790, 967453750, 968448710, 969443670, 970438630, 971433590, 972433590, 973428550, 974428550, 975423510, 976418470, 977413430, 978408390, 979403350, 980398310, 981393270, 982388230, 983388230, 984388230, 985388230, 986388230, 987388230, 988388230, 989388230, 990388230, 991388230, 992388230, 993388230, 994388230};
        int sum = 0;
        sum+=ret[N/1000000];
        for(int i=N/1000000*1000000+1;i<=N;i++){
            if(isnum(i)){
                sum++;
            }
        }
        return sum;
    }
};

bool isnum(int n){
    int a[10]={0};
    while(n){
        int ge = n%10;
        a[ge]++;
        if(a[ge]>1){
            return true;
        }
        n/=10;
    }
    return false;
}

int mn(int m ,int n){
    int cnt =0;
    for(int i=m;i<=n;i++){
        if(isnum(i)){
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    Solution Solution1;
    cout<<Solution1.numDupDigitsAtMostN(1000)<<endl;
    return 0;
}

/*int main()
{
    int a[1001]={0};
    int cnt=0;
    for(int i=1;i<=1000;i++){
        a[i]=a[i-1]+ mn( (i-1)*1000000 + 1,i*1000000);
    }
    for(int i=0;i<1001;i++){
        cout<<a[i]<<", ";
    }
    return 0;
}
*/
