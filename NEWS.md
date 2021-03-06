<!-- -*- mode: markdown; fill-column: 8192 -*- -->

## v1.9

*2019-02-08*
Changes to bring in line differences between Keyboardio and Ergodox.


## v1.8

Changes were influenced by one week's worth of logging data.

* Added `LEAD`+`E` = `GUI`+`E` and removed dedicated shortcut
* Added active window toggling with `ALT`+`ESC`. Double tap for previous active window or `ALT`+`SHIFT`+`ESC`.
* Switch `TAB` and MVMNT layer functionality with NMBR.
* Added toggle NMBR layer key to right side of keyboard.
* Updated swap layer to swap thumb clusters.
* Updated logging flag to be false by default.
* Moved `PGUP`/`PGDWN`.
* Added `MEH`+`S` for snipping shortcut and `MEH`+`W` for Divvy shortcut.
* Fixed `LEAD`+`L` and `LEAD`+`U`.
* Added startup light display.
* Removed QWERTY layer.
* Moved PLVR layer to FUNCTION layer (one must hold down the FUNC while pressing the PLVR key since FUNC is OSL).
* Updated the SWPHNDS layer lighs to be 1 and 3 on.
* Moved `CTRL` away from pinky to thumb - based on heatmap data usage (`CTRL` is used 3-5%).
* Added function, movement and number layer keys to thumb cluster for one handed usage.
* Moved F5 to right handed thumb cluster for easier access - based on heatmap data usage.
* Moved swap hands layer to thumb cluster - test to see if my data is accurate or if my usage is accidental strokes.
* Moved `LGUI` to less prime location due to lack of use based on heatmap data.
* Removed right thumb cluster function layer due to lack of use based on heatmap data.

## v1.7

*2018-12-17*
* Added `LEAD`+`D` turns off keylogger console print statements.

*2018-12-05*

* Cleaned up `LEAD` + `S`/`F` bug due to short character length variable - increased from 5 to 10.
* Added `GUI`+`E` button to shortcut open windows explorer.
* Added `LEAD`+`W`+`M` = `GUI`+`UP` to maximize window.

*2018-12-03*

* Removed `CTRL`+`SHIFT` when held or `SPACE` when tapped from movement layer due to lack of use. End up manually using `CTRL`+`SHIFT` when navigating excel.
* Added `Print Screen` to movement layer.
* Removed leader `T` = `ALT`+`TAB`.
* Removed various depreciated tap dance keys.
* Moved `RESET` into function layer out of base.
* Removed thumb cluster tap `CTRL` and `ALT` due to lack of use.
* Added F2 and F5 to base layer left hand due to frequency of use. Will be able to rename files in Windows while right hand is on mouse and open SimCorp windows without switching layers.
* Added `LEAD`+`F` = 'from:' for Outlook navigation.
* Removed web page navigation button due to lack of use and replaced with `HYPER`.
* Changed `LEAD`+`S`+`C`+`D` to `LEAD`+`S` due to frequency of use.

*2018-12-02*

* Moved over `0` and `.` on numberpad layer to match planck.
* Moved around numpad math to align with base layer logic.
* Added `LEAD` commands:
	- `LEAD` + `L` = `GUI`+`L` (Lock)
	- `LEAD` + `U` = `CTRL` + `ALT` + `DEL` (Unlock)
* Removed mouse movement keys - was not able to abopt it into my workflow no matter how hard I forced it.
* Added symbols to movement layer.
* Added function layer for F keys.
* ~~Moved `GUI` + `L` and `CTRL` + `ALT` + `DEL` buttons down to thumb cluster.~~ Stupid idea - they were fine where they were. 
* Moved around unused thumb cluster keys.
* Added extra `ALT` ~~and `CTRL`~~ to be accessable by left hand. 


## v1.6

*2018-09-10*

* Changed symbols, number and movement layer activators from momentarily and toggle layer to just toggle. Button would not switch fast enough when typing frantically.
* Added lead shortcuts
   - scd --> [SCD]
   - svr --> joshua.bragge.svr
   - db --> joshua.bragge.db
   - jb --> joshua.bragge
   - t --> alt+tab

## v1.5

*2018-07-11*

### Plover
* Unblocked the PLOVER key such that you can now exit PLOVER layout by tapping the entry button.

*2018-07-08*

### Base
* Removed TD for `CTRL`+letter for `S`, `Z`, `X`, `C`, `V`. Makes typing words like `PROCESSING` difficult.
* Added layer LED colours.

*2018-07-08*

### Base
* Removed `CTRL` and `ALT` from right side of keyboard due to infrequency of use.
* Moved the symbol layer to the right hand key.
* Replaced the symbol layer on the left hand with the number pad key.
* Removed thumb `LALT` due to number of accidential hits and infrequency of use. 
* Replaced tap `CTRL` on left hand with regular `CTRL` due to issues with accidental taps.
* Removed `SHIFT`+`TAB` due to the button not working reliabily through virtual machines and moved `DEL` over.
* Reorganized thumb clusters - added `INS` and `Application` buttons.
* Added sudo Swap Hands function (will revist the QMK functionality in the future).
* Added `LEAD` key to right hand thumb cluster and moved `LGUI` key over to left thumb cluster.
	- `LEAD` - `M`+`E`+`H` = `¯\(ツ)_/¯`
* Removed the TD F5, F2 and F4 from the numbers as focus should be on the symbols layer.
* Added TD for `CTRL`+letter for `S`, `Z`, `X`, `C`, `V`

### Number
* Moved number pad layout out from symbol.

### Symbols
* Moved the stacked symbols on the left hand to the right.

### Movement
* Moved right click button to more accessable and logical location near the left thumb.
* Removed dedicated copy paste due to infrequency of use.
* Added `HOME` and `END` for navigation purposes on the right hand near the arrow keys.
* Removed `KC_MS_ACCEL1` due to infrequency of use.

## v1.4

*2018-06-17*

### Base
* Moved the `DEL` key so it is more accessable by the thumb.
* Moved the `LALT` key because it was being unused.

### Movement
* Lowered mouse movement speed.

### Qwerty 
* Added qwerty layer.

### Plover
* Added plover layer.

## v1.3

*2018-06-11*

### Base
* Removed double tap `TAB` for `ALT`+`TAB`. The double tap was not fast enough when being used multiple times in a row.
* Added a dedicated `ALT`+`TAB` button to replace `DEL` button. 
* Added movement layer back to `TAB`.
* Removed `ENTER` on the right hand pinky.
* Moved `\` to the right hand as to keep all the punctuation and symbols together.
* Reorganized punctuation so most used is easier to reach.
* Added tap for `-` double tap for `_`.

### Movement
* Moved `CTRL`+`SHIFT` key to the other side so it is possible to hold movement layer key while highlighting text with arrows.
* Reverted VIM mouse keys to WASD keys because layout was just too difficult to adjust to.
* Moved mouse wheel buttons to right hand to be consistent with VIM layout.
* Moved mouse click buttons so they are not blocking other usefuly keys on the base layer for navigation


## v1.2

*2018-04-24*
* Increased mouse speed from 2 to 5.
* Removed arrow keys from symbol layer so that the layer can more closely mimic a number pad.
* Added tap `2`, double tap for  `F2`.
* Removed tap for `TAB` hold for `SHIFT` from thumb key.
* Removed Movement layer activation from `TAB` key
* Added tap for `TAB` double tap for `ALT`+`TAB`.
* Added web page navigation keys.
* Duplicated `CTRL` and `ALT` keys so they are accessable by both thumb keys.

## v1.1

*2018-04-23*

* Moved the movement and symbol layer to an area that is more comfortable.
* Added quick access to page up and page down.
* Added a `DEL` button where `TAB` usually is.
* Added double tap over numbers for most used function keys.
* Movement and symbol layer on the right hand side is going unused.

## v1.0

*2018-04-21*

Initial version.
