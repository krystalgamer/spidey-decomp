#include "pcdcBkup.h"
#include "non_win32.h"

#include "validate.h"

#include <cstring>

EXPORT CHAR gMemorycardPath[688];

EXPORT char* gMusicTracks[1264] =
{ 
	"L1A1_00.bik",
	"L1A1_01.bik",
	"L1A1_02.bik",
	"L1A1_03.bik",

	"L1A1_04.bik",
	"L1A1_05.bik",
	"L1A1_06.bik",
	"L1A1_07.bik",
	"L1A1_08.bik",
	"L1A1_09.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L1A1_10.bik",
	"L1A1_11.bik",
	"L1A1_12.bik",
	"L1A1_13.bik",
	"L1A1_14.bik",
	"L1A1_15.bik",
	"L1A1_16.bik",
	"L1A1_17.bik",

	"L1A1_18.bik",
	"L1A1_19.bik",
	"L1A1_20.bik",
	"L1A1_21.bik",
	"L1A1_22.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L1A2_00.bik",
	"L1A2_01.bik",
	"L1A2_02.bik",
	"L1A2_03.bik",
	"L1A2_04.bik",
	"L1A2_05.bik",

	"L1A2_06.bik",

	"L1A2_07.bik",

	"L1A2_08.bik",
	"L1A2_09.bik",
	"L1A2_10.bik",
	"L1A2_11.bik",
	"L1A2_12.bik",
	"L1A2_13.bik",
	"L1A2_14.bik",
	"L1A2_15.bik",
	"L1A3_00.bik",
	"L1A3_01.bik",

	"L1A3_02.bik",
	"L1A3_03.bik",
	"L1A3_04.bik",
	"blank.bik",
	"L1A3_06.bik",
	"L1A3_07.bik",

	"L1A3_08.bik",
	"L1A3_29.bik",
	"L1A3_30.bik",
	"L1A3_31.bik",
	"L1A3_32.bik",

	"L1A3_33.bik",
	"L1A3_34.bik",
	"L1A3_35.bik",
	"L1A3_09.bik",
	"L1A3_10.bik",

	"L1A3_11.bik",
	"L1A3_12.bik",
	"L1A3_13.bik",
	"L1A3_14.bik",
	"L1A3_15.bik",
	"L1A3_16.bik",
	"L1A3_17.bik",
	"L1A3_18.bik",
	"blank.bik",
	"L1A3_20.bik",
	"L1A3_21.bik",
	"L1A3_22.bik",

	"L1A3_36.bik",
	"L1A3_37.bik",
	"L1A4_00.bik",
	"L1A4_01.bik",
	"L1A4_02.bik",
	"L1A4_03.bik",
	"L1A4_04.bik",
	"L1A4_05.bik",
	"L1A4_06.bik",
	"L1A4_07.bik",
	"L1A4_08.bik",
	"L1A4_09.bik",
	"L1A4_10.bik",
	"L1A4_11.bik",

	"L1A4_12.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"fight0.bik",
	"impact0.bik",
	"impact1.bik",
	"intro0.bik",
	"mystery0.bik",
	"scary0.bik",
	"sewer0.bik",
	"slowrol0.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L1A3_23.bik",
	"L1A3_24.bik",
	"L1A3_25.bik",
	"L1A3_26.bik",

	"L1A3_27.bik",
	"L1A3_28.bik",
	"L1A3_38.bik",
	"L1A3_39.bik",
	"L1A3_40.bik",

	"L1A3_41.bik",
	"L1A3_42.bik",
	"L1A3_43.bik",
	"L1A3_44.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L2A1_15.bik",
	"L2A1_20.bik",
	"L2A1_26a.bik",
	"L2A1_27a.bik",
	"L2A1_36.bik",
	"L2A1_37.bik",
	"L2A1_21.bik",
	"L2A1_22.bik",

	"L2A1_06.bik",
	"L2A1_23.bik",
	"L2A1_24.bik",
	"L2A1_29.bik",
	"L2A1_33.bik",
	"L2A1_35.bik",
	"L2A1_31.bik",
	"L2A1_32.bik",
	"L2A1_17.bik",
	"L2A1_18.bik",

	"L2A1_19.bik",

	"L2A1_34.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L2A2_01.bik",
	"L2A2_01A.bik",
	"L2A2_02.bik",
	"L2A2_03a.bik",
	"L2A2_04.bik",
	"L2A2_05.bik",
	"L2A2_06.bik",
	"L2A2_07.bik",
	"L2A2_08.bik",
	"L2A2_09.bik",
	"L2A2_10.bik",

	"L2A2_11.bik",
	"L2A2_12.bik",
	"L2A2_13.bik",
	"L2A2_14.bik",
	"L2A2_15.bik",
	"L2A2_16.bik",
	"L2A2_17A.bik",
	"L2A2_18A.bik",

	"L2A2_18B.bik",
	"L2A2_19.bik",
	"L2A2_20.bik",
	"L2A2_21.bik",
	"L2A2_22.bik",
	"L2A2_23.bik",
	"L2A2_24.bik",
	"L2A2_25.bik",
	"L2A2_26.bik",
	"L2A2_27.bik",
	"L2A2_28.bik",
	"L2A2_29.bik",
	"L2A2_30.bik",
	"L2A2_31.bik",
	"L2A2_32.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L8A5a_00.bik",
	"L8A5a_01.bik",

	"L8A5a_02.bik",
	"L8A5a_03.bik",
	"L8A5a_04.bik",
	"L8A5a_05.bik",
	"L8A5a_06.bik",
	"L8A5a_07.bik",
	"L8A5a_08.bik",
	"L8A5a_09.bik",
	"L8A5a_10.bik",

	"L8A5a_11.bik",

	"L8A5a_12.bik",

	"L8A5a_13.bik",
	"L8A5a_14.bik",
	"L8A5a_15.bik",
	"L8A5a_16.bik",
	"L8A5a_17.bik",
	"L8A5a_18.bik",
	"L8A5a_19.bik",
	"L8A5a_20.bik",
	"L8A5a_21.bik",
	"L8A5a_22.bik",
	"L8A5a_23.bik",
	"L8A5a_24.bik",
	"L8A5a_25.bik",
	"L8A5a_26.bik",
	"L8A5a_27.bik",
	"L8A5a_28.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L3A1_01.bik",
	"L3A1_02.bik",
	"L3A1_03.bik",
	"L3A1_04.bik",
	"L3A1_05.bik",
	"L3A1_06.bik",
	"L3A1_07.bik",
	"L3A1_08.bik",
	"L3A1_09.bik",
	"L3A1_10.bik",

	"L3A1_11.bik",
	"L3A1_12.bik",
	"L3A1_13.bik",
	"L3A1_14.bik",
	"L3A1_15.bik",
	"L3A1_16.bik",
	"L3A2_00.bik",
	"L3A2_01.bik",
	"L3A2_02.bik",
	"L3A2_03.bik",
	"L3A2_04.bik",
	"L3A2_05.bik",
	"L3A2_06.bik",
	"L3A2_07.bik",

	"L3A2_08.bik",

	"L3A2_09.bik",
	"L3A2_10.bik",
	"L3A2_11.bik",
	"L3A2_12.bik",
	"L3A2_13.bik",
	"L3A2_14.bik",
	"L3A2_15.bik",
	"L3A2_16.bik",
	"L3A2_17.bik",
	"L3A2_18.bik",
	"L3A2_19.bik",
	"L3A2_20.bik",
	"L3A2_21.bik",

	"L3A2_22.bik",

	"L3A2_23.bik",

	"L3A2_24.bik",

	"L3A2_25.bik",

	"L3A2_26.bik",
	"L3A2_27.bik",
	"L3A2_28.bik",
	"L3A2_29.bik",
	"L3A2_30.bik",
	"L3A2_31.bik",
	"L3A1_17.bik",
	"L3A1_18.bik",
	"L3A1_19.bik",
	"L3A1_20.bik",
	"L3A1_21.bik",
	"L3A3_00.bik",
	"L3A4_00.bik",
	"L3A4_01.bik",

	"L3A4_02.bik",
	"L3A5_00.bik",
	"L3A5_01.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L4A1_01.bik",
	"L4A1_02.bik",
	"L4A1_03.bik",
	"L4A1_04.bik",
	"L4A1_05.bik",
	"L4A1_06.bik",
	"L4A1_07.bik",
	"L4A1_08.bik",
	"L4A1_09.bik",
	"L4A1_10.bik",
	"L4A1_11.bik",
	"L4A1_12.bik",
	"L4A1_13.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L4A1_20.bik",
	"L4A1_21.bik",
	"L4A1_22.bik",
	"L4A1_23.bik",
	"L4A1_24.bik",
	"L4A1_25.bik",
	"L4A1_26.bik",

	"L4A1_27.bik",
	"L4A1_28.bik",
	"L4A1_29.bik",
	"L4A1_30.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"spid_00.bik",
	"spid_01.bik",
	"spid_02.bik",
	"spid_03.bik",
	"spid_04.bik",
	"spid_05.bik",
	"spid_06.bik",
	"spid_07.bik",
	"spid_08.bik",
	"spid_09.bik",
	"spid_10.bik",
	"spid_11.bik",
	"spid_12.bik",
	"spid_13.bik",
	"spid_14.bik",
	"spid_15.bik",

	"spid_16.bik",
	"spid_17.bik",
	"spid_18.bik",
	"spid_19.bik",
	"spid_20.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"kid_00.bik",
	"kid_01.bik",
	"kid_02.bik",
	"kid_03.bik",
	"kid_04.bik",
	"kid_05.bik",

	"kid_06.bik",
	"kid_07.bik",

	"kid_08.bik",
	"sp_alt00.bik",
	"sp_alt01.bik",
	"sp_alt02.bik",
	"kid_09.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L7A5_37.bik",
	"L7A5_38.bik",
	"L7A5_39.bik",
	"L7A5_40.bik",

	"L7A5_41.bik",
	"L7A5_42.bik",
	"L7A5_43.bik",
	"L7A5_44.bik",
	"L7A5_45.bik",
	"L7A5_46.bik",
	"L7A5_47.bik",

	"L7A5_48.bik",
	"L7A5_49.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L8A1_15.bik",
	"L8A1_16.bik",
	"L8A1_17.bik",
	"L8A1_18.bik",
	"L8A1_19.bik",
	"L8A1_20.bik",
	"L8A1_21.bik",
	"L8A1_22.bik",
	"L8A1_23.bik",
	"L8A1_24.bik",
	"L8A1_25.bik",

	"L8A1_26.bik",
	"L8A1_27.bik",
	"L8A1_28.bik",
	"L8A1_29.bik",
	"L8A1_30.bik",
	"L8A1_31.bik",
	"L8A1_32.bik",
	"L8A1_33.bik",
	"L8A1_34.bik",
	"L8A4_27.bik",
	"L8A4_28.bik",
	"L8A4_29.bik",
	"L8A4_30.bik",
	"L8A4_31.bik",
	"L8A4_32.bik",
	"L8A4_33.bik",
	"L8A4_34.bik",
	"L8A4_35.bik",
	"L8A4_36.bik",

	"L8A4_37.bik",
	"L8A4_38.bik",
	"L8A4_39.bik",
	"L8A4_40.bik",
	"L8A4_41.bik",
	"L8A4_42.bik",

	"L8A4_43.bik",
	"L8A4_44.bik",
	"L8A4_45.bik",
	"L8A4_46.bik",
	"L8A4_47.bik",
	"L8A4_48.bik",
	"L8A4_49.bik",
	"L8A4_50.bik",
	"L8A4_51.bik",
	"L8A4_52.bik",
	"L8A4_53.bik",
	"L8A4_54.bik",
	"L8A6_16.bik",
	"L8A6_17.bik",
	"L8A6_18.bik",
	"L8A6_19.bik",
	"L8A6_20.bik",
	"L8A6_21.bik",
	"L8A6_22.bik",
	"L8A6_23.bik",
	"L8A2ST00.bik",
	"L8A2ST01.bik",
	"L8A2ST02.bik",
	"L8A2ST03.bik",
	"L8A2ST04.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L5A1_00.bik",
	"L5A1_01.bik",
	"L5A1_02.bik",
	"L5A1_03.bik",
	"L5A1_04.bik",
	"L5A1_05.bik",
	"L5A1_06.bik",

	"L5A1_07.bik",
	"L5A1_08.bik",
	"L5A1_09.bik",
	"L5A1_10.bik",

	"L5A1_11.bik",
	"L5A1_12.bik",
	"L5A1_13.bik",

	"L5A1_14.bik",
	"L5A1_15.bik",
	"L5A1_16.bik",
	"L5A1_17.bik",
	"L5A1_18.bik",
	"L5A1_19.bik",
	"L5A1_20.bik",
	"L5A1_21.bik",
	"L5A1_22.bik",

	"L5A1_23.bik",
	"L5A1_24.bik",
	"L5A1_25.bik",
	"L5A1_26.bik",
	"L5A1_27.bik",
	"L5A1_28.bik",

	"L5A1_29.bik",
	"L5A1_30.bik",
	"L5A1_31.bik",
	"L5A2_00.bik",

	"L5A2_01.bik",
	"L5A2_02.bik",
	"L5A2_03.bik",

	"L5A2_04.bik",
	"L5A2_05.bik",
	"L5A2_06.bik",

	"L5A2_07.bik",
	"L5A2_08.bik",
	"L5A2_09.bik",
	"L5A2_10.bik",
	"L5A2_11.bik",
	"L5A2_12.bik",
	"L5A2_13.bik",
	"L5A2_14.bik",
	"L5A2_15.bik",
	"L5A3_00.bik",
	"L5A3_01.bik",
	"L5A3_02.bik",
	"L5A3_03.bik",
	"L5A3_04.bik",

	"L5A3_05.bik",
	"L5A3_06.bik",
	"L5A3_07.bik",
	"L5A3_08.bik",
	"L5A3_09.bik",
	"L5A3_10.bik",
	"L5A3_11.bik",
	"L5A3_12.bik",
	"L5A3_13.bik",
	"blank.bik",
	"blank.bik",
	"L5A4_00.bik",
	"L5A4_01.bik",
	"L5A5_00.bik",

	"L5A4_02.bik",
	"L5A4_03.bik",
	"L5A5_01.bik",

	"L5A5_02.bik",
	"L5A5_03.bik",
	"L5A5_04.bik",
	"L5A5_05.bik",
	"L5A5_06.bik",
	"L5A5_07.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L5A1_32.bik",
	"L5A1_33.bik",
	"L5A1_34.bik",
	"L5A1_35.bik",
	"L5A1_36.bik",
	"L5A1_37.bik",
	"L5A1_38.bik",

	"L5A1_39.bik",
	"L5A1_40.bik",
	"L5A1_41.bik",
	"L5A1_42.bik",
	"L5A1_43.bik",
	"L5A1_44.bik",
	"L5A2_16.bik",
	"L5A2_17.bik",
	"blank.bik",

	"L5A6_00.bik",
	"L5A6_01.bik",
	"L7A1_16.bik",
	"L7A1_17.bik",
	"L7A1_18.bik",
	"L7A1_19.bik",
	"L7A1_20.bik",
	"L7A1_21.bik",
	"L7A1_22.bik",

	"L7A1_23.bik",
	"L7A1_24.bik",
	"L7A1_25.bik",
	"L7A1_26.bik",
	"L7A1_27.bik",

	"L7A1_28.bik",

	"L7A1_29.bik",
	"L5A7_00.bik",
	"L5A7_01.bik",
	"L7A1_30.bik",
	"L7A1_31.bik",
	"L7A1_32.bik",
	"L7A1_33.bik",

	"L7A1_34.bik",
	"L7A1_35.bik",
	"L7A1_36.bik",
	"L7A1_37.bik",
	"L7A1_38.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L6A2_00.bik",
	"L6A2_01.bik",
	"L6A2_02.bik",
	"L6A2_03.bik",
	"L6A2_04.bik",
	"L6A2_05.bik",
	"L6A2_06.bik",
	"L6A2_07.bik",
	"L6A2_08.bik",
	"L6A2_09.bik",
	"L6A1_00.bik",
	"L6A4_41.bik",
	"L6A4_42.bik",
	"L6A4_43.bik",
	"L6A4_44.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L6A4_00.bik",
	"L6A4_01.bik",
	"L6A4_02.bik",
	"L6A4_03.bik",
	"L6A4_04.bik",
	"L6A4_05.bik",
	"L6A4_06.bik",

	"L6A4_07.bik",
	"L6A4_08.bik",
	"L6A4_09.bik",
	"L6A4_10.bik",
	"L6A4_11.bik",
	"L6A4_12.bik",

	"L6A4_13.bik",
	"L6A4_14.bik",
	"L6A4_15.bik",
	"L6A4_16.bik",
	"L6A4_17.bik",
	"L6A4_18.bik",
	"L6A4_19.bik",
	"L6A4_20.bik",

	"L6A4_21.bik",
	"L6A4_22.bik",
	"L6A4_23.bik",
	"L6A4_24.bik",
	"L6A4_25.bik",

	"L6A4_26.bik",
	"L6A4_27.bik",
	"L6A4_30.bik",
	"L6A4_31.bik",

	"L6A4_32.bik",
	"L6A4_33.bik",
	"L6A3_00.bik",
	"L6A3_01.bik",
	"L6A3_02.bik",
	"L6A3_03.bik",
	"L6A3_04.bik",

	"L6A3_05.bik",
	"L6A3_06.bik",
	"L6A3_07.bik",
	"L6A3_08.bik",
	"L6A3_09.bik",
	"L6A3_10.bik",
	"L6A3_11.bik",
	"L6A3_12.bik",
	"L6A3_13.bik",
	"L6A3_14.bik",
	"L6A3_15.bik",
	"L6A3_16.bik",
	"L6A3_17.bik",
	"L6A3_18.bik",
	"L6A3_19.bik",

	"L6A3_20.bik",
	"L6A3_21.bik",
	"L6A3_22.bik",
	"L6A3_23.bik",
	"L6A3_24.bik",
	"L6A4_34.bik",

	"L6A4_35.bik",
	"L6A4_36.bik",
	"L6A4_37.bik",
	"L6A4_38.bik",
	"L6A4_39.bik",
	"L6A4_40.bik",
	"L7A1_00.bik",
	"L7A1_01.bik",
	"L7A1_02.bik",
	"L7A1_03.bik",
	"L7A1_04.bik",
	"L7A1_05.bik",
	"L7A1_06.bik",

	"L7A1_07.bik",
	"L7A1_08.bik",
	"L7A1_09.bik",
	"L7A1_10.bik",
	"L7A1_11.bik",
	"L7A1_12.bik",
	"L7A1_13.bik",
	"L7A1_14.bik",
	"L7A1_15.bik",
	"L7A2_00.bik",
	"L7A2_01.bik",
	"L7A2_02.bik",
	"L7A2_03.bik",
	"L7A2_04.bik",
	"L7A2_05.bik",
	"L7A2_06.bik",
	"L7A2_07.bik",
	"L7A2_08.bik",
	"L7A2_09.bik",

	"L7A2_10.bik",
	"L7A2_11.bik",
	"L7A2_12.bik",
	"L7A2_13.bik",

	"L7A2_14.bik",
	"L7A2_15.bik",
	"L7A3_00.bik",
	"L7A3_01.bik",
	"L7A3_02.bik",
	"L7A3_03.bik",
	"L7A3_04.bik",

	"L7A3_05.bik",
	"L7A3_06.bik",
	"L7A3_07.bik",
	"L7A3_08.bik",
	"L7A3_09.bik",

	"L7A3_10.bik",
	"L7A3_11.bik",
	"L7A3_12.bik",
	"L7A3_13.bik",
	"L7A3_14.bik",
	"L7A3_15.bik",
	"L7A5_04a.bik",
	"L7A5_04b.bik",
	"L7A5_05a.bik",
	"L7A5_05b.bik",
	"L7A5_06a.bik",
	"L7A5_06b.bik",

	"L7A5_07.bik",
	"L7A5_08a.bik",
	"L7A5_08b.bik",
	"L7A5_09a.bik",
	"L7A5_09b.bik",
	"L7A5_10a.bik",
	"L7A5_10b.bik",

	"L7A5_10c.bik",
	"L7A5_10d.bik",
	"L7A5_11.bik",
	"L7A5_12a.bik",
	"L7A5_13.bik",
	"L7A5_14a.bik",
	"L7A5_14b.bik",
	"L7A5_14c.bik",

	"L7A5_15a.bik",
	"L7A5_15b.bik",
	"L7A5_15c.bik",
	"L7A5_15d.bik",
	"L7A5_16.bik",
	"L7A5_17.bik",
	"L7A5_18.bik",
	"L7A5_19.bik",
	"L7A5_20.bik",
	"blank.bik",
	"blank.bik",
	"L7A3_16.bik",
	"L7A3_17.bik",
	"L7A3_18.bik",
	"L7A3_19.bik",
	"L7A3_20.bik",
	"L7A3_21.bik",
	"L7A3_22.bik",
	"L7A3_23.bik",
	"L7A3_24.bik",
	"L7A3_25.bik",
	"L7A3_26.bik",
	"L7A4_16.bik",
	"L7A4_17.bik",
	"L7A4_18.bik",
	"L7A4_19.bik",
	"L7A4_20.bik",
	"Victry01.bik",
	"Victry02.bik",
	"Victry03.bik",
	"Victry04.bik",
	"Victry05.bik",
	"Victry06.bik",
	"Victry07.bik",
	"Victry08.bik",

	"Victry09.bik",
	"Victry10.bik",
	"Victry11.bik",
	"Victry12.bik",
	"Victry13.bik",
	"Victry14.bik",
	"Victry15.bik",
	"Victry16.bik",
	"Victry17.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"Hurt01.bik",

	"Hurt02.bik",
	"Hurt03.bik",
	"Hurt04.bik",
	"Hurt05.bik",
	"Hurt06.bik",
	"Hurt07.bik",

	"Hurt08.bik",
	"Hurt09.bik",
	"Hurt10.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L7A4_00.bik",
	"L7A4_01.bik",
	"L7A4_02.bik",
	"L7A4_03.bik",
	"L7A4_04.bik",

	"L7A4_05.bik",
	"L7A4_06.bik",
	"L7A4_07.bik",
	"L7A4_08.bik",
	"L7A4_09.bik",

	"L7A4_10.bik",

	"L7A4_11.bik",

	"L7A4_12.bik",
	"L7A4_13.bik",
	"L7A4_14.bik",
	"L7A4_15.bik",
	"L7A5_21.bik",
	"L7A5_22.bik",
	"L7A5_23.bik",
	"L7A5_24.bik",
	"L7A5_25.bik",
	"L7A5_26.bik",
	"L7A5_27.bik",
	"L7A5_28.bik",

	"L7A5_29.bik",
	"L7A5_30.bik",
	"L7A5_31.bik",
	"L7A5_32.bik",
	"L7A5_33.bik",

	"L7A5_34.bik",
	"L7A5_35.bik",
	"L7A5_36.bik",
	"L8A1_00.bik",
	"L8A1_01.bik",
	"L8A1_02.bik",
	"L8A1_03.bik",
	"L8A1_04.bik",
	"L8A1_05.bik",
	"L8A1_06.bik",
	"L8A1_07.bik",
	"L8A1_08.bik",
	"L8A1_09.bik",
	"L8A1_10.bik",

	"L8A1_11.bik",
	"L8A1_12.bik",
	"L8A1_13.bik",
	"L8A1_14.bik",
	"blank.bik",
	"L8A2_00.bik",
	"L8A2_01.bik",
	"L8A2_02.bik",
	"L8A2_03.bik",
	"L8A2_04.bik",
	"L8A2_05.bik",
	"L8A2_06.bik",
	"L8A2_07.bik",
	"L8A2_08.bik",

	"L8A2_09.bik",
	"L8A2_10.bik",
	"L8A2_11.bik",
	"L1A2a_1.bik",
	"song_00.bik",
	"song_full.bik",
	"stan_00.bik",
	"L8A4_00.bik",
	"L8A4_01.bik",
	"L8A4_02.bik",

	"L8A4_03.bik",
	"L8A4_04.bik",
	"L8A4_05.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L8A4_06.bik",
	"L8A4_07.bik",

	"blank.bik",
	"blank.bik",
	"L8A4_08.bik",

	"L8A4_09.bik",

	"L8A4_10.bik",
	"L8A4_11.bik",
	"L8A4_12.bik",
	"L8A4_13.bik",
	"L8A4_14.bik",
	"L8A4_15.bik",
	"L8A4_16.bik",
	"L8A4_17.bik",
	"L8A4_18.bik",
	"L8A4_19.bik",
	"L8A4_20.bik",
	"L8A4_21.bik",
	"L8A4_22.bik",
	"L8A4_23.bik",
	"L8A4_24.bik",

	"L8A4_25.bik",
	"L8A4_26.bik",
	"L8A3_00.bik",
	"L8A3_01.bik",
	"L8A3_02.bik",
	"L8A3_03.bik",
	"L8A3_04.bik",
	"L8A3_05.bik",
	"L8A3_06.bik",
	"L8A3_07.bik",

	"L8A3_08.bik",
	"L8A3_09.bik",
	"L8A3_10.bik",
	"L8A3_11.bik",
	"L8A3_12.bik",
	"L8A3_13.bik",
	"L8A3_14.bik",
	"L8A3_15.bik",
	"L8A5_01.bik",
	"L8A5_02.bik",
	"L8A5_03.bik",
	"L8A5_04.bik",
	"L8A5_05.bik",

	"L8A5_06.bik",
	"L8A5_07.bik",
	"L8A5_08.bik",
	"L8A5_09.bik",
	"L8A5_10.bik",
	"L8A5_11.bik",
	"L8A5_12.bik",
	"L8A5_13.bik",

	"L8A5_14.bik",
	"L8A5_15.bik",
	"L8A5_16.bik",
	"L8A5_17.bik",
	"L8A5_18.bik",
	"L8A5_19.bik",
	"L8A5_20.bik",
	"L8A5_21.bik",
	"L8A5_22.bik",
	"L8A5_23.bik",
	"L8A5_24.bik",
	"L8A5_25.bik",
	"L8A5_26.bik",
	"L8A5_27.bik",
	"L8A5_28.bik",
	"L8A5_29.bik",
	"L8A5_30.bik",
	"L8A5_31.bik",
	"L8A5_32.bik",
	"L8A3_16.bik",
	"L8A3_17.bik",
	"L8A3_18.bik",
	"L8A3_19.bik",
	"L8A3_20.bik",
	"L8A3_21.bik",
	"L8A3_22.bik",

	"L8A3_23.bik",

	"L8A3_24.bik",
	"L8A3_25.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",

	"blank.bik",
	"blank.bik",
	"blank.bik",
	"L8A5_33.bik",
	"L8A5_34.bik",
	"L8A5_35.bik",
	"L8A5_36.bik",
	"L8A5_37.bik",
	"L8A5_38.bik",
	"L8A5_39.bik",
	"L8A5_40.bik",
	"L8A5_41.bik",
	"L8A5_42.bik",
	"L8A5_43.bik",
	"L8A5_44.bik",
	"L8A5_45.bik",
	"L8A5_46.bik",
	"L8A5_47.bik",
	"L8A5_48.bik",
	"L8A6_00.bik",
	"L8A6_01.bik",
	"L8A6_02.bik",
	"L8A6_03.bik",
	"L8A6_04.bik",
	"L8A6_05.bik",
	"L8A6_06.bik",
	"L8A6_07.bik",
	"L8A6_08.bik",
	"L8A6_09.bik",
	"L8A6_10.bik",
	"L8A6_11.bik",
	"L8A6_12.bik",
	"L8A6_13.bik",
	"L8A6_14.bik",

	"L8A6_15.bik",

	"stan_00.bik",
	"stan_01.bik",
	"stan_02.bik",
	"stan_03.bik",
	"stan_04.bik",
	"stan_05.bik",

	"stan_06.bik",
	"stan_07.bik",
	"stan_08.bik",
	"stan_09.bik",
	"stan_10.bik",

	"stan_11.bik",
	"stan_12.bik",
	"stan_13.bik",
	"stan_14.bik",
	"stan_15.bik",
	"stan_16.bik",
	"stan_17.bik",
	"stan_18.bik",
	"stan_19.bik",

	"stan_20.bik",
	"stan_21.bik",
	"stan_22.bik",
	"stan_23.bik",
	"stan_24.bik",
	"stan_25.bik",
	"stan_26.bik",

	"stan_27.bik",
	"stan_28.bik",
	"stan_29.bik",

	"stan_30.bik",
	"stan_31.bik",
	"stan_32.bik",

	"stan_33.bik",
	"stan_34.bik",
	"stan_35.bik",
	"stan_36.bik",
	"stan_37.bik",

	"stan_38.bik",
	"stan_39.bik",
	"stan_40.bik",
	"stan_41.bik",
	"song_vab.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik",
	"blank.bik"
};

// @Ok
// @Matching
INLINE i32 buCalcBackupFileSize(
		u32,
		u32,
		u32 a3)
{
	i32 result = a3 >> 9;
	if ((a3 & 0x1FF) > 0)
		++result;
	return result;
}

// @Ok
// @Matching
i32 buGetDiskFree(i32, i32)
{
	return 0x7FFFFFFF;
}

// @Ok
// @Matching
char* MUSICTRACKS_GetTrackName(i32 a1)
{
	return gMusicTracks[a1];
}

// @Ok
// @Matching
i32 buInit(i32, i32, void*, void (*a4)(void))
{
	GetCurrentDirectoryA(0x104u, gMemorycardPath);
	strcat(gMemorycardPath, "\\save\\");
	CreateDirectoryA(gMemorycardPath, 0);
	a4();
	return 0;
}

// @Ok
// @Matching
void buSetCompleteCallback(i32 (*pFunc)(i32, i32, i32, u32))
{
	for (i32 i = 0; i < 8; i++)
	{
		pFunc(i, 1, 0, 0);
	}
}

// @Ok
// @Matching
i32 buIsReady(i32)
{
	return 1;
}

// @Ok
// @Matching
i32 buIsFormat(i32)
{
	return 0;
}

// @Ok
// @Matching
i32 buStat(i32)
{
	return 0;
}

// @Ok
// @Matching
i32 buGetLastError(i32)
{
	return 0;
}

// @Ok
// @Matching
i32 buExit(void)
{
	return 0;
}

// @Ok
// @Matching
i32 buGetFileSize(
		i32 a1,
		const char* a2)
{
	char v6[260];
	strcpy(v6, gMemorycardPath);
	strcat(v6, a2);

	FILE* v2 = fopen(v6, "rb");
	if (v2)
	{
		fseek(v2, 0, 2);

		i32 v4 = ftell(v2);
		fclose(v2);
		return buCalcBackupFileSize(0, 0, v4);
	}

	return -1;

}

// @Ok
// @Matching
i32 buLoadFile(
		i32 a1,
		const char* a2,
		void* a3,
		i32 a4)
{
	char v7[260];

	strcpy(v7, gMemorycardPath);
	strcat(v7, a2);

	FILE *v4 = fopen(v7, "rb");
	if (!v4)
		return -249;

	fread(a3, 0x200u, a4, v4);
	fclose(v4);
	return 0;
}

// @Ok
// @Matching
i32 buAnalyzeBackupFileImage(
		SBackupFile* a1,
		void* a2)
{

	i32 *pA2 = reinterpret_cast<i32*>(a2);
	i32 v2;
	memcpy(&v2, pA2, 4);

	a1->mBackupSize = v2;
	a1->pCardHead = reinterpret_cast<SCardHead*>(&pA2[1]);
	return 0;
}

// @Ok
// @Matching
i32 buMakeBackupFileImage(
		void* a1,
		SBackupFile* a2)
{
	memcpy(a1, &a2->mBackupSize, 4);
	memcpy(&static_cast<i32*>(a1)[1], a2->pCardHead->Magic, a2->mBackupSize);

	return buCalcBackupFileSize(0, 0, a2->mBackupSize);
}

// @Ok
// @Matching
i32 buSaveFile(
		i32,
		const char* a2,
		void *a3,
		i32 a4,
		SDCCardTime* a5)
{
	char v8[260];

	strcpy(v8, gMemorycardPath);
	strcat(v8, a2);

	FILE *v5 = fopen(v8, "wb");
	if (!v5)
		return -248;

	fwrite(a3, 0x200u, a4, v5);
	fclose(v5);
	return 0;
}

void validate_SBackupFile(void)
{
	VALIDATE_SIZE(SBackupFile, 0x60);

	VALIDATE(SBackupFile, mName, 0x0);
	VALIDATE(SBackupFile, mDesc, 0x12);

	VALIDATE(SBackupFile, field_34, 0x34);

	VALIDATE(SBackupFile, field_44, 0x44);
	VALIDATE(SBackupFile, field_48, 0x48);
	VALIDATE(SBackupFile, field_4C, 0x4C);
	VALIDATE(SBackupFile, field_4E, 0x4E);
	VALIDATE(SBackupFile, field_50, 0x50);
	VALIDATE(SBackupFile, field_54, 0x54);

	VALIDATE(SBackupFile, pCardHead, 0x58);
	VALIDATE(SBackupFile, mBackupSize, 0x5C);
}
