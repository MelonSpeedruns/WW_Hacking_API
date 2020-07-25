
typedef struct NPC_Test_class {
  fopNpc_npc_c parent;
  dNpc_EventCut_c eventActor;
  
  request_of_phase_process_class mPhaseRequest;
  dNpc_PathRun_c mPathRun;
  
  PTMF mCurrAction;
  s8 mCurrCutIdx;
} NPC_Test_class;

void _prolog();
void _epilog();
void _unresolved();
int daNPCTest_Create(NPC_Test_class* this);
int daNPCTest_IsDelete(NPC_Test_class* this);
int daNPCTest_Delete(NPC_Test_class* this);
int daNPCTest_Draw(NPC_Test_class* this);
int daNPCTest_Execute(NPC_Test_class* this);
void daNPCTest__eventOrder(NPC_Test_class* this);
void daNPCTest__checkOrder(NPC_Test_class* this);
void daNPCTest__event_proc(NPC_Test_class* this);
void daNPCTest__privateCut(NPC_Test_class* this);
void daNPCTest__event_actionInit(NPC_Test_class* this, int staffId);
void daNPCTest__event_action(NPC_Test_class* this);
void daNPCTest__setMtx(NPC_Test_class* this, bool unk);
bool daNPCTest__chkAttention(NPC_Test_class* this);
void daNPCTest__setAttention(NPC_Test_class* this, bool unk);
int daNPCTest__next_msgStatus(NPC_Test_class* this, ulong* msgIDPtr);
ulong daNPCTest__getMsg(NPC_Test_class* this);
void daNPCTest__anmAtr(NPC_Test_class* this, ushort unk);
int daNPCTest__set_action(NPC_Test_class* this, PTMF action, void* unk);
void daNPCTest__wait_action(NPC_Test_class* this, void* unk);
int daNPCTest__talk(NPC_Test_class* this);
void daNPCTest__endEvent(NPC_Test_class* this);

profile_method_class l_daNPCTest_Method = {
  .parent = {
    .mpCreate = &daNPCTest_Create,
    .mpDelete = &daNPCTest_Delete,
    .mpExecute = &daNPCTest_Execute,
    .mpIsDelete = &daNPCTest_IsDelete,
    .mpDraw = &daNPCTest_Draw,
  },
  .mpUnkFunc1 = 0,
  .mpUnkFunc2 = 0,
  .mpUnkFunc3 = 0,
};

const f_pc_profile__Profile_Actor g_profile_NPC_Test = {
  .parent = {
    .mLayerID = -3,
    .mListID = 7, // Affects execution order of actors in a given frame. Lower numbers execute first.
    .mListPrio = -3,
    .mPName = 0xB5, // Actor ID
    0,
    0,
    .mpMtd0 = &g_fpcLf_Method,
    .mSize = sizeof(NPC_Test_class),
    .mSizeOther = 0,
    .mDefaultParameters = 0,
    .mpMtd1 = &g_fopAc_Method,
  },
  
  .mDrawPriority = 0x9F,
  0,
  0,
  .mpMtd2 = &l_daNPCTest_Method,
  .mStatus = 0,
  .mActorType = fopAc_ac_c__Type__Some_NPCs,
  .mCullType = 0,
  0,
  0,
};

const fopNpc_npc_c__vtbl daNpc_Test_c_vtbl = {
  0,
  0,
  .next_msgStatus = (pointer)&daNPCTest__next_msgStatus,
  .getMsg = (pointer)&daNPCTest__getMsg,
  .anmAtr = (pointer)&daNPCTest__anmAtr,
};

const PTMF daNPCTest__Actions[] = {
  {
    .this_delta = 0,
    .vtbl_offset = -1,
    .func = (pointer)&daNPCTest__wait_action,
  },
};

#define daNPCTest__Num_Cuts 1
const char* daNPCTest__Cut_Names[daNPCTest__Num_Cuts] = {
  "DUMMY_CUT",
};
