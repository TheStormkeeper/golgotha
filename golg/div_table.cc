/********************************************************************** <BR>
  This file is part of Crack dot Com's free source code release of
  Golgotha. <a href="http://www.crack.com/golgotha_release"> <BR> for
  information about compiling & licensing issues visit this URL</a> 
  <PRE> If that doesn't help, contact Jonathan Clark at 
  golgotha_source@usa.net (Subject should have "GOLG" in it) 
***********************************************************************/

static const i4_float div_table[] = 
{
  1.0    ,1.0/  1,1.0/  2,1.0/  3,1.0/  4,1.0/  5,1.0/  6,1.0/  7,1.0/  8,1.0/  9,
  1.0/ 10,1.0/ 11,1.0/ 12,1.0/ 13,1.0/ 14,1.0/ 15,1.0/ 16,1.0/ 17,1.0/ 18,1.0/ 19,
  1.0/ 20,1.0/ 21,1.0/ 22,1.0/ 23,1.0/ 24,1.0/ 25,1.0/ 26,1.0/ 27,1.0/ 28,1.0/ 29,
  1.0/ 30,1.0/ 31,1.0/ 32,1.0/ 33,1.0/ 34,1.0/ 35,1.0/ 36,1.0/ 37,1.0/ 38,1.0/ 39,
  1.0/ 40,1.0/ 41,1.0/ 42,1.0/ 43,1.0/ 44,1.0/ 45,1.0/ 46,1.0/ 47,1.0/ 48,1.0/ 49,
  1.0/ 50,1.0/ 51,1.0/ 52,1.0/ 53,1.0/ 54,1.0/ 55,1.0/ 56,1.0/ 57,1.0/ 58,1.0/ 59,
  1.0/ 60,1.0/ 61,1.0/ 62,1.0/ 63,1.0/ 64,1.0/ 65,1.0/ 66,1.0/ 67,1.0/ 68,1.0/ 69,
  1.0/ 70,1.0/ 71,1.0/ 72,1.0/ 73,1.0/ 74,1.0/ 75,1.0/ 76,1.0/ 77,1.0/ 78,1.0/ 79,
  1.0/ 80,1.0/ 81,1.0/ 82,1.0/ 83,1.0/ 84,1.0/ 85,1.0/ 86,1.0/ 87,1.0/ 88,1.0/ 89,
  1.0/ 90,1.0/ 91,1.0/ 92,1.0/ 93,1.0/ 94,1.0/ 95,1.0/ 96,1.0/ 97,1.0/ 98,1.0/ 99,
  1.0/100,1.0/101,1.0/102,1.0/103,1.0/104,1.0/105,1.0/106,1.0/107,1.0/108,1.0/109,
  1.0/110,1.0/111,1.0/112,1.0/113,1.0/114,1.0/115,1.0/116,1.0/117,1.0/118,1.0/119,
  1.0/120,1.0/121,1.0/122,1.0/123,1.0/124,1.0/125,1.0/126,1.0/127,1.0/128,1.0/129,
  1.0/130,1.0/131,1.0/132,1.0/133,1.0/134,1.0/135,1.0/136,1.0/137,1.0/138,1.0/139,
  1.0/140,1.0/141,1.0/142,1.0/143,1.0/144,1.0/145,1.0/146,1.0/147,1.0/148,1.0/149,
  1.0/150,1.0/151,1.0/152,1.0/153,1.0/154,1.0/155,1.0/156,1.0/157,1.0/158,1.0/159,
};
