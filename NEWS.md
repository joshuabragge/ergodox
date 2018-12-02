<!-- -*- mode: markdown; fill-column: 8192 -*- -->

## v1.7

*2018-12-02*

* Moved over `0` and `.` on numberpad layer to match planck.
* Moved around numpad math to align with base layer logic.
* Added `LEAD` commands:
	- `LEAD` + `L` = `GUI`+`L` (Lock)
	- `LEAD` + `U` = `CTRL` + `ALT` + `DEL` (Unlock)

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
