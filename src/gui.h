/*
 * Copyright (c) 2018 Milan Suk
 *
 * Use of this software is governed by the Business Source License included
 * in the LICENSE file and at www.mariadb.com/bsl11.
 *
 * Change Date: 2024-11-01
 *
 * On the date above, in accordance with the Business Source License, use
 * of this software will be governed by version 2 or later of the General
 * Public License.
 */

void GuiItemTheme_init(void);
void GuiItemTheme_goRed(void);
void GuiItemTheme_goBlue(void);
void GuiItemTheme_goGreen(void);
void GuiItemTheme_goOcean(void);
void GuiItemTheme_goGrey(void);

typedef struct Win_s Win;
typedef struct Image1_s Image1;

typedef struct GuiImage_s GuiImage;
GuiImage* GuiImage_new1(Image1 image);
GuiImage* GuiImage_new4(Image4 image);

typedef struct GuiItem_s GuiItem;
typedef void GuiItemCallback(GuiItem* self);			//callback
typedef void GuiItemCallbackMove(GuiItem* dst, GuiItem* src);	//callback drag & drop

typedef struct GuiItemLayout_s GuiItemLayout;
GuiItemLayout* GuiItemLayout_new(Quad2i grid);
UBIG GuiItemLayout_getWheelV(GuiItemLayout* self);
void GuiItemLayout_setWheelV(GuiItemLayout* self, UBIG wheel);
void GuiItemLayout_setDrawBorder(GuiItemLayout* self, BOOL drawBorder);
void GuiItemLayout_setScrollVPos(GuiItemLayout* self, BIG pos);
void GuiItemLayout_addColumn(GuiItemLayout* self, UINT pos, int value);
void GuiItemLayout_addRow(GuiItemLayout* self, UINT pos, int value);
void GuiItemLayout_setDrop(GuiItemLayout* self, GuiItemCallback* drop);
void GuiItemLayout_setResize(GuiItemLayout* self, GuiItemCallback* resize);
void GuiItemLayout_setBackgroundWhite(GuiItemLayout* self, BOOL drawBackgroundWhite);
void GuiItemLayout_setDrawBackground(GuiItemLayout* self, BOOL drawBackground);
void GuiItemLayout_resizeArrayColumn(GuiItemLayout* self, UINT n);
void GuiItemLayout_resizeArrayRow(GuiItemLayout* self, UINT n);
void GuiItemLayout_setScrollV(GuiItemLayout* self, DbValue scrollV);


void GuiItem_delete(GuiItem* self);
void GuiItem_setResize(GuiItem* self, BOOL resize);
GuiItem* GuiItem_getParent(const GuiItem* self);
void GuiItem_setIcon(GuiItem* self, GuiImage* icon);
BOOL GuiItem_setShow(GuiItem* self, BOOL show);
void GuiItem_remove(GuiItem* self);
void GuiItem_freeSubs(GuiItem* self);
void GuiItem_setGrid(GuiItem* self, Quad2i grid);
void GuiItem_setCoord(GuiItem* self, Quad2i coord);
void GuiItem_setEnable(GuiItem* self, BOOL enable);
void GuiItem_setEnableMsg(GuiItem* self, DbValue msg, BOOL reverse);
//void* GuiItem_addSub(GuiItem* self, GuiItem* sub);
void* GuiItem_addSubName(GuiItem* self, const char* name, GuiItem* sub);
void GuiItem_removeSub(GuiItem* self, UBIG i);
void GuiItem_removeSubPtr(GuiItem* self, GuiItem* item);
UBIG GuiItem_numSub(const GuiItem* self);
GuiItem* GuiItem_getSub(GuiItem* self, UBIG i);
const GuiItem* GuiItem_getSubConst(const GuiItem* self, UBIG i);
void GuiItem_setCallClick(GuiItem* self, GuiItemCallback* click);
void GuiItem_setShortcutKey(GuiItem* self, BOOL shortOutsideEdit, UBIG shortKey_extra, UNI shortKey_id, GuiItemCallback* key);
void GuiItem_resize(GuiItem* self, GuiItemLayout* layout, Win* win);

void GuiItem_setTouch(GuiItem* self, BOOL touch);

Quad2i GuiItem_getSubMaxGrid(GuiItem* self);
Quad2i GuiItem_getSubMaxCoord(GuiItem* self);

BOOL GuiItem_setFirstCursor(GuiItem* self);
BOOL GuiItem_setNextCursor(GuiItem* self);

BOOL GuiItem_shortcut(GuiItem* self);
void GuiItem_draw(GuiItem* self, Win* win, Image4* img);
void GuiItem_update(GuiItem* self, Win* win);
void GuiItem_touch(GuiItem* self, Win* win);

void GuiItem_setName(GuiItem* self, const char* name);
void* GuiItem_findName(GuiItem* self, const char* name);
void* GuiItem_findNameType(GuiItem* self, const char* name, UINT type);

void GuiItem_closeParentLevel(GuiItem* self);

BIG GuiItem_getRow(GuiItem* self);
void GuiItem_setRow(GuiItem* self, BIG row, UBIG index);

void GuiItem_setChangeSize(GuiItem* self, UINT changeSizeVertical, DbValue changeSizeValue, BOOL changeSizeMoveOut);
void GuiItem_setDropCallback(GuiItem* self, const char* nameSrc, const char* nameDst, BOOL dropVertival, GuiItemCallbackMove* dragDropMove);
void GuiItem_setDrop(GuiItem* self, const char* nameSrc, const char* nameDst, BOOL dropVertival, DbRows dropMove, BIG dropRow);
void GuiItem_setDropIN(GuiItem* self, const char* name, DbRows dropMoveIn);

void GuiItem_setAttribute(GuiItem* self, const char* name, BIG value);
BIG GuiItem_findAttribute(GuiItem* self, const char* name);

typedef struct GuiItemText_s GuiItemText;
typedef struct GuiItemEdit_s GuiItemEdit;
typedef struct GuiItemButton_s GuiItemButton;
typedef struct GuiItemSlider_s GuiItemSlider;
typedef struct GuiItemParticles_s GuiItemParticles;
typedef struct GuiItemMenu_s GuiItemMenu;
typedef struct GuiItemComboStatic_s GuiItemComboStatic;
typedef struct GuiItemComboDynamic_s GuiItemComboDynamic;
typedef struct GuiItemCheck_s GuiItemCheck;
typedef struct GuiItemTable_s GuiItemTable;
typedef struct GuiItemList_s GuiItemList;
typedef struct GuiItemSwitch_s GuiItemSwitch;
typedef struct GuiItemTags_s GuiItemTags;

GuiItem* GuiItemButton_new(Quad2i grid, DbValue text);
GuiItem* GuiItemButton_newAlphaEx(Quad2i grid, DbValue text, GuiItemCallback* call);
GuiItem* GuiItemButton_newNoCenterEx(Quad2i grid, DbValue text, GuiItemCallback* call);
GuiItem* GuiItemButton_newClassicEx(Quad2i grid, DbValue text, GuiItemCallback* call);
GuiItem* GuiItemButton_newBlackEx(Quad2i grid, DbValue text, GuiItemCallback* call);
GuiItem* GuiItemButton_newWhiteEx(Quad2i grid, DbValue text, GuiItemCallback* call);
GuiItem* GuiItemButton_newImage(Quad2i grid, GuiImage* image, GuiItemCallback* call);
void GuiItemButton_setDescription(GuiItemButton* self, DbValue description);
void GuiItemButton_setCircle(GuiItemButton* self, BOOL circle);
void GuiItemButton_setTextCenter(GuiItemButton* self, BOOL center);
void GuiItemButton_setPressed(GuiItemButton* self, BOOL stayPressed);
void GuiItemButton_setPressedEx(GuiItemButton* self, BOOL stayPressed, BOOL stayPressedLeft, BOOL stayPressedRight);

GuiItem* GuiItemEdit_newEx(Quad2i grid, DbValue text, DbValue description, GuiItemCallback* callFinish);
GuiItem* GuiItemEdit_new(Quad2i grid, DbValue text, DbValue description);
void GuiItemEdit_setHighlightIfContent(GuiItemEdit* self, BOOL drawHighlightIfContent);
void GuiItemEdit_setPasswordStars(GuiItemEdit* self, BOOL stars);
void GuiItemEdit_setFnChanged(GuiItemEdit* self, GuiItemCallback* clickChanged);
void GuiItemEdit_clickActivate(GuiItemEdit* self, GuiItemCallback* clickActivate);
void GuiItemEdit_setShowPicker(GuiItemEdit* self, BOOL showPicker, BOOL pickerOpen, BOOL pickerFolder, BOOL pickerMultiple, const UNI* pickerAction, const UNI* pickerExts);
double GuiItemEdit_getNumber(GuiItemEdit* self);
void GuiItemEdit_setNumber(GuiItemEdit* self, double value);
void GuiItemEdit_saveCache(void);
void GuiItemEdit_setTextLevel(GuiItemEdit* self, int text_level);
void GuiItemEdit_showDescription(GuiItemEdit* self, BOOL showDescription);
const UNI* GuiItemEdit_getText(const GuiItemEdit* self);
void GuiItemEdit_setText(GuiItemEdit* self, const UNI* str);

GuiItem* GuiItemText_new(Quad2i grid, BOOL enableCentring, DbValue text, DbValue description);
GuiItem* GuiItemText_newUnderline(Quad2i grid, BOOL enableCentring, DbValue text, DbValue description, BOOL formatBrowser, BOOL formatEmail);
void GuiItemText_setCursorHand(GuiItemText* self, BOOL cursorHand);
void GuiItemText_setWhiteBack(GuiItemText* self, BOOL on);
void GuiItemText_setEnableSelect(GuiItemText* self, BOOL enableSelect);
const UNI* GuiItemText_getText(const GuiItemText* self);
void GuiItemText_setText(GuiItemText* self, const UNI* str);
double GuiItemText_getNumber(const GuiItemText* self);
void GuiItemText_setNumber(GuiItemText* self, double value);

GuiItem* GuiItemTextMulti_new(Quad2i grid, DbValue text);

GuiItem* GuiItemComboStatic_new(Quad2i grid, DbValue value, const UNI* options, DbValue description);
GuiItem* GuiItemComboStatic_newEx(Quad2i grid, DbValue value, const UNI* options, DbValue description, GuiItemCallback* call);
UBIG GuiItemComboStatic_getValue(const GuiItemComboStatic* self);

GuiItem* GuiItemComboDynamic_new(Quad2i grid, BOOL warningBackground, DbRows value, DbValue optionsValues, DbRows optionsLinks, DbValue description);
GuiItem* GuiItemComboDynamic_newEx(Quad2i grid, BOOL warningBackground, DbRows value, DbValue optionsValues, DbRows optionsLinks, DbValue description, GuiItemCallback* call);
void GuiItemComboDynamic_setFirstOptionToValue(GuiItemComboDynamic* self);
void GuiItemComboDynamic_resetValue(GuiItemComboDynamic* self);
BIG GuiItemComboDynamic_getValueRow(const GuiItemComboDynamic* self);
void GuiItemComboDynamic_setOpenCall(GuiItemComboDynamic* self, GuiItemCallback* openCall);
void GuiItemComboDynamic_setOptionsLinks(GuiItemComboDynamic* self, DbRows optionsLinks);
void GuiItemComboDynamic_setExtraInfo(GuiItemComboDynamic* self, DbTable* extra_table, BIG extra_row);
DbTable* GuiItemComboDynamic_getExtraTable(const GuiItemComboDynamic* self);
BIG GuiItemComboDynamic_getExtraRow(const GuiItemComboDynamic* self);

GuiItem* GuiItemSlider_newEx(Quad2i grid, DbValue minValue, DbValue maxValue, DbValue jumpValue, DbValue value, DbValue description, DbValue left, DbValue right, GuiItemCallback* call);
GuiItem* GuiItemSlider_new(Quad2i grid, DbValue minValue, DbValue maxValue, DbValue jumpValue, DbValue value, DbValue description);

double GuiItemSlider_getNumber(GuiItemSlider* self);
void GuiItemSlider_setNumber(GuiItemSlider* self, double value);

GuiItemParticles* GuiItemParticles_new(Quad2i grid, const Image1 logo);
void GuiItemParticles_startAnim(GuiItemParticles* self, double time_sec);

GuiItem* GuiItemMenu_new(Quad2i grid, DbValue value, BOOL circle);
GuiItem* GuiItemMenu_newImage(Quad2i grid, GuiImage* image);
void GuiItemMenu_addItem(GuiItemMenu* self, DbValue text, GuiItemCallback* click);
void GuiItemMenu_addItemEx(GuiItemMenu* self, DbValue text, GuiItemCallback* click, BOOL confirm, BIG attr_type);
void GuiItemMenu_addItemIcon(GuiItemMenu* self, GuiImage* icon, DbValue text, GuiItemCallback* click, BOOL confirm, BIG attr_type);
void GuiItemMenu_addItemEmpty(GuiItemMenu* self);
void GuiItemMenu_clearItems(GuiItemMenu* self);
DbValue* _GuiItemMenu_findItem(GuiItemMenu* self, const UNI* name);
void GuiItemMenu_setUnderline(GuiItemMenu* self, BOOL underline);
void GuiItemMenu_setContext(GuiItemMenu* self, GuiItemLayout* context);
void GuiItemMenu_setCenter(GuiItemMenu* self, BOOL textCenter);
void GuiItemMenu_setHighligthBackground(GuiItemMenu* self, BOOL highligthBackground);

GuiItem* GuiItemBox_newEmpty(Quad2i coord);
GuiItem* GuiItemBox_newCd(Quad2i coord, Rgba cd);
GuiItem* GuiItemBox_newImage(Quad2i coord, GuiImage* image);
GuiItem* GuiItemBox_newShortcut(Quad2i coord, UBIG shortKey_extra, UNI shortKey_id, GuiItemCallback* click);

GuiItem* GuiItemCheck_newEx(Quad2i grid, DbValue value, DbValue description, GuiItemCallback* click);
GuiItem* GuiItemCheck_new(Quad2i grid, DbValue value, DbValue description);
BOOL GuiItemCheck_isActive(GuiItemCheck* self);

GuiItemTable* GuiItemTable_new(Quad2i grid, BIG tableRow, DbRows filter, BOOL showHeader, BOOL showAddRecord, DbValue scrollV, DbValue scrollH, DbValue selectGrid);
GuiItemLayout* GuiItemTable_buildPage(BIG viewRow, BOOL showRowID, BOOL onlyRead);
void GuiItemTable_setRowSize(GuiItemTable* self, UINT rowSize);
void GuiItemTable_clickSelectCalendar(GuiItem* self);


GuiItem* GuiItemList_new(Quad2i grid, DbRows filter, GuiItem* skin, DbValue description);
GuiItem* GuiItemList_newButtons(Quad2i grid, DbRows source, DbValue button, DbValue description, GuiItemCallback* clickButton);
//GuiItem* GuiItemList_newButtonsDrag(Quad2i grid, DbRows source, DbValue buttonText, DbValue description, GuiItemCallback* buttonCall);
GuiItem* GuiItemList_newButtonsMenu(Quad2i grid, DbRows source, DbValue description, DbValue buttonText, GuiItemCallback* buttonCall, GuiItemMenu** out_menu);
//GuiItem* GuiItemList_newButtonsMenuDrag(Quad2i grid, DbRows source, DbValue description, DbValue buttonText, GuiItemCallback* buttonCall, GuiItemMenu** out_menu);
void GuiItemList_setShowScroll(GuiItemList* self, BOOL showScroll);
void GuiItemList_setShowRemove(GuiItemList* self, BOOL showRemove);
void GuiItemList_setShowBorder(GuiItemList* self, BOOL showBorder);
void GuiItemList_disableScrollSend(GuiItemList* self);
void GuiItemList_setAsGrid(GuiItemList* self, UINT numColumns);
DbRows GuiItemList_getInfo(const GuiItemList* self);
void GuiItemList_setClickRemove(GuiItemList* self, GuiItemCallback* clickRemove);

GuiItem* GuiItemSwitch_new(Quad2i coord, DbValue value);
GuiItem* GuiItemSwitch_addItem(GuiItemSwitch* self, int pos, GuiItem* item);
double GuiItemSwitch_getNumber(const GuiItemSwitch* self);
void GuiItemSwitch_setNumber(GuiItemSwitch* self, double value);

typedef GuiItemLayout* GuiItemTagsCallback(DbColumn* column);
GuiItem* GuiItemTags_new(Quad2i grid, DbRows source, DbValues columns, GuiItemTagsCallback* callbackAdd, GuiItemTagsCallback* callbackItem, BOOL relativeAdd, BOOL relativeItem, BOOL setRowAdd, BOOL setRowItem, DbValue imagePreview);

typedef struct Win_s Win;

BOOL GuiItemRoot_new(void);
void GuiItemRoot_delete(void);
void GuiItemRoot_setContent(GuiItem* item);
void GuiItemRoot_setContentLayout(GuiItemLayout* layout);
void GuiItemRoot_addDialog(GuiItem* item);
void GuiItemRoot_addDialogLayout(GuiItemLayout* layout);
GuiItemLayout* GuiItemRoot_createDialogLayout(Vec2i maxGrid, DbValue name, GuiItem* content, GuiItemCallback* clickClose);
//GuiItem* GuiItemRoot_getContent(void);
void GuiItemRoot_setTouch(BOOL enable);	 //disable during particle effect
BOOL GuiItemRoot_needResize(Win* win);
void GuiItemRoot_center(GuiItemLayout* layout, Win* win);
void GuiItemRoot_resizeAll(void);
void GuiItemRoot_key(Win* win);
void GuiItemRoot_tick(BOOL doUpdate, BOOL doDraw, Win* win, Quad2i* redrawRect);

typedef struct GuiItemColor_s GuiItemColor;
GuiItemColor* GuiItemColor_new(Quad2i grid, DbValue value, BOOL pickuper);

typedef struct GuiItemGroup_s GuiItemGroup;
GuiItem* GuiItemGroup_new(Quad2i grid, UBIG viewRow, DbRows filter, DbValue scrollH);