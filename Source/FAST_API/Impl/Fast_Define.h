/*******************************************************************************

Դ��������:  Fast_Define.h
�������Ȩ: �������ӹɷ����޹�˾��Ȩ����
ϵͳ����:   �������ϵͳ5.0��Ŀ
ģ������:   �Ϻ�Level2������
����˵��:   FAST�Ļ������Ͷ���
����ĵ�:   
����:       ֣����

*******************************************************************************/

#ifndef  H5DS_FAST_DEFINE_H
#define  H5DS_FAST_DEFINE_H

#include "../Include/Basic_Types.h"
#include <vector>
#include <map>
using std::vector ;
using std::map ;

// Fast Template
#define FAST_TEMPLATE_NAME "template"
#define FAST_SEQUENCE_NAME "sequence"

#define FFT_STRING          "string"
#define FFT_INT32           "int32"
#define FFT_INT64           "int64"
#define FFT_UINT32          "uint32"
#define FFT_UINT64          "uint64"
#define FFT_DOUBLE          "double"
#define FFT_SEQUENCE        "sequence"
#define FFT_LENGTH          "length"
#define FFT_NULL_TYPE       "NULL_TYPE"

#define FFOP_CONSTANT  "constant"
#define FFOP_DEFAULT   "default"
#define FFOP_COPY      "copy"
#define FFOP_INCREMENT "increment"
#define FFOP_NOOP      "NoOp"

#define FFPSE_OPTIONAL  "optional"
#define FFPSE_MANDATORY "Mandatory"

#define STEP_HEADER_FLAG                                  "8=STEP.1.0.0"
#define STEP_HEADER_SIZE                                  12
#define STEP_LEN_FLAG                                     "9="
#define STEP_LEN_SIZE                                     2
#define STEP_MSGSEQID_FLAG                                "10072="
#define STEP_MSGSEQID_SIZE                                6
#define STEP_TYPE_FLAG                                    "35="
#define STEP_TYPE_SIZE                                    3
#define STEP_SENDTIME_FLAG                                "52="
#define STEP_SENDTIME_SIZE                                3

#define STEP_SEQUENCE_FLAG                                "34="
#define STEP_SEQUENCE_SIZE                                3

#define FASTDATA_LEN_FLAG                                 "95="
#define FASTDATA_LEN_SIZE                                 3
#define FASTDATA_FLAG                                     "96="
#define FASTDATA_SIZE                                     3
#define FAST_TAIL_LENGTH                                  7

#define MIN_STEP_LEN                                      30
#define STEP_FIELD_DELIM                                  0x01

#define MAX_FAST_TEMPLATE                                  40
#define UA3101_SLOT                                        0
#define UA3102_SLOT                                        1
#define UA3103_SLOT                                        2
#define UA3104_SLOT                                        3
#define UA3105_SLOT                                        4
#define UA3106_SLOT                                        5
#define UA3107_SLOT                                        6
#define UA1115_SLOT                                        7
#define UA3111_SLOT                                        12
#define UA3113_SLOT                                        14
#define UA3115_SLOT                                        16
// FAST2.0
#define UA2102_SLOT                                        21
#define UA2107_SLOT                                        22
#define UA3201_SLOT                                        23
#define UA3202_SLOT                                        24
#define UA5102_SLOT                                        25

// Logon Tag
#define FASTTAG_ENCRYPT_METHOD                             98
#define FASTTAG_HEARTBT_INT                                108
// FAST-Rebuild Request Tag
#define FAST_REQTYPE_REBUILD                               "UA1201"
#define FAST_REQTYPE_LOGON                                 "A"
#define FASTTAG_CATEGORY                                   10142
#define FASTTAG_REBUILD_METHOD                             10075
#define FASTTAG_TRADE_CHANNEL                              10077
#define FASTTAG_BEGIN_ID                                   10073
#define FASTTAG_END_ID                                     10074
#define FASTTAG_REBUILD_STATUS                             10076
#define FASTTAG_TEXT                                       58

// FAST��Ϣ����
enum  Fast_Type
{
    FAST_NONE_TYPE                    = 0    ,
    FAST_LOGON                        = 'A'  ,  //��¼
    FAST_LOGOUT                       = 5    ,  //�ǳ�
    FAST_REFERENCE_DATA               = 101  ,  //��ʼ����Ϣ��
    FAST_REBUILD                      = 1201 ,  //REBUILD
    FAST_SYSTEM_MESSAGE               = 1202 ,  //SystemMessage
    FAST_ANNOUNCEMENT                 = 1100 ,  //������Ϣ
    FAST_TRANSACTION                  = 3101 ,  //�����Ϣ
    FAST_MARKET_DATA                  = 3102 ,  //�г���Ϣ
    FAST_ORDER_RANKING                = 3103 ,  //��������
    FAST_TRANSACTION_RANKING_INDUSTRY = 3104 ,  //��ҵ�������
    FAST_SINGLE_ORDER_CANCEL_RANKING  = 3105 ,  //���ʳ�������
    FAST_CONSOLIDATED_CANCEL_RANKING  = 3106 ,  //�ۼƳ�������
    FAST_NGTS_VIRTUAL_ACTION_PRICE    = 3107 ,  //���⾺��
    FAST_NGTS_INDEX                   = 3113 ,  //ָ��������Ϣ
    FAST_NGTS_MARKET_OVERVIEW         = 3115 ,  //�г��ſ���Ϣ
    FAST_NGTS_ORDER_QUEUE             = 3111 ,  //ί�ж���
    
    // FAST2.0 - NEW
    //FAST2_MARKET_OVERVIEW             = 3115 ,
    FAST2_AH_MARKET_DATA              = 2102 ,
    FAST2_AH_VIRUTAL_AUCTION_PRICE    = 2107 ,
    FAST2_AH_MARKET_OVERVIEW          = 1115 ,
    FAST2_NGTS_TRANSACTION            = 3201 ,
    FAST2_NGTS_MARKET_DATA            = 3202 ,
    FAST2_LEVEL1_DATA                 = 5102 ,

    //��ծ ������Ȩ
    FAST_ZQQDBJCJHQ                    =6302,
    FAST_ZQCJMX                        =6301,
    FAST_ISP_DATA                      =8102,
    FAST_OPT_LEVEL1                    =9502,
    //��ծ ������Ȩ

    //sz
    FAST_SZ_LOGON                     = 'A'    ,  // SLZ2 ��¼           (ԭʼ����: A) ʹ��ʱ���õ� FAST_LOGON
    FAST_SZ_LOGOUT                    = 5      ,  // SLZ2 �ǳ�           (ԭʼ����: 5) ʹ��ʱ���õ� FAST_LOGOUT
    FAST_SZ_REBUILD                   = 2      ,  // SZL2 �ؽ�           (ԭʼ����: 2)
    FAST_SZ_HEARTBEAT                 = 1      ,  // SZL2 ����           (ԭʼ����: UA001)
    FAST_SZ_SYSPARAM                  = 9002   ,  // SZL2 �г���������   (ԭʼ����: UA002, �����˴�Ӧ�����2, ������FAST_SZ_REBUILD��ͻ, �ʶ����9002)
    FAST_SZ_USERREPORT                = 3      ,  // SLZ2 �û���Ϣ����   (ԭʼ����: UA003)
    FAST_SZ_STOCKINFO                 = 101    ,  // SLZ2 ֤ȯ��Ϣ       (ԭʼ����: UA101) 
    FAST_SZ_STOCKSTATUS               = 102    ,  // SLZ2 ֤ȯ״̬       (ԭʼ����: UA102)
    FAST_SZ_SNAPSHOT                  = 103    ,  // SLZ2 �������       (ԭʼ����: UA103)
    FAST_SZ_INDEX                     = 104    ,  // SLZ2 ָ������       (ԭʼ����: UA104)
    FAST_SZ_ORDER                     = 201    ,  // SLZ2 ���ί��       (ԭʼ����: UA201)
    FAST_SZ_TRADE                     = 202    ,  // SLZ2 ��ʳɽ�       (ԭʼ����: UA202)
    FAST_SZ_BULLETIN                  = 401    ,  // SLZ2 ���漰��ֵ��Ϣ (ԭʼ����: UA401)
    //sz

    //δ֪����Ϣ
    FAST_UNKNOWN_TYPE                 = 1000000,
} ;

// FAST����Ʒ���
#define MAX_FAST_CATEGORY           20

// FAST��Ʒ���
enum Fast_Category
{
    FAST_CID_REFERENCE                = 1 ,     //�ο�����
    FAST_CID_INIT_FILE                = 3 ,     //��ʼ���ļ�
    FAST_CID_MARKETDATA               = 6 ,     //�������
    FAST_CID_TRANSACTION              = 7 ,     //��ʳɽ�
    FAST_CID_AH_MARKETDATA            = 9 ,     //A+H�������
    FAST_CID_STATIC_FILE              = 10 ,    //��̬����: ������ȯ�ļ�,�ص�ָ�������ļ�,����ʽ����ֵ�ļ�
    FAST_CID_LEVEL1                   = 13      //Level1�������
} ;

// RebuildMethod
enum RebildMethod
{
    RMETHOD_BY_CATEGORY_SEQUENCE_NUMBER = 1 ,   //���ݲ�Ʒ�����Ϣ���
    RMETHOD_FULL_IMATE_REBUILD          = 2 ,   //�ò�Ʒ����µ�ȫ����Ϣ
    RMETHOD_TRANSACTION                 = 3     //��ʳɽ��Ļز�
} ;

// RebuildStatus
enum RebuildStatus
{
    RSTATUS_OK                          = 1 ,   //�ɹ�,�������ݷ���
    RSTATUS_PARTIALLY_COMPLETED         = 2 ,   //���ֳɹ�
    RSTATUS_REJECTED                    = 3 ,   //�ܾ�
    RSTATUS_DATA_NOT_AVAILABLE          = 4     //�޴�����
} ;

//Fast�ֶ�ֵ����
enum Fast_FieldType
{
    FFT_Null_Type = 0 ,
    FFT_String ,
    FFT_UString,
    FFT_Int8   ,
    FFT_UInt8  ,
    FFT_Int16  ,
    FFT_UInt16 ,
    FFT_Int32  ,
    FFT_UInt32 ,
    FFT_Int64  ,
    FFT_UInt64 ,
    FFT_Sequence ,
    FFT_Length
} ;

//Fast�����Ĳ�������
enum Fast_OP
{
    OP_NULL = 0 ,
    OP_Constant ,
    OP_Default  ,
    OP_Copy     ,
    OP_Increment,
    OP_Delta
};

//Fast�ֶεĴ�����
enum Fast_Presence
{
    PRES_Mandatory = 0,
    PRES_Optional
} ;

//Fast�ֶ�ֵ
#define FAST_MAXSTRINGLEN 64
struct Fast_Value
{
    Fast_FieldType  field_type ;      //ֵ����
    uint32          decimal_place ;   //С��λ

    union
    {
        int32   l4 ;
        int64   l8 ;
        double  d8 ;
        char    str[FAST_MAXSTRINGLEN] ;
    } val ;

    Fast_Value(){ memset(this, 0, sizeof(*this)); }

    void Reset()
    {
	    memset(&val, 0xff, sizeof val);
    }

    bool IsAssigned()
    {
	    unsigned char *p = (unsigned char *)&val;
	    for (size_t i = 0; i < sizeof val; i++)
	    {
		    if (p[i] != 0xff)
		    {
			    return true;
		    }
	    }

	    return false;
     }
} ;

//Fastģ���ֶ�����
struct FastMsg_Templ ;
#define FAST_FIELDNAME_LEN 50
struct Fast_TemplField
{
    uint32               field_id ;         //�ֶε�ID
    Fast_OP              field_op ;         //�ֶε�OP
    Fast_FieldType       field_type ;       //�ֶε�����
    char                 field_name[FAST_FIELDNAME_LEN] ; //�ֶ�����
    Fast_Presence        field_pres ;       //�ֶεĴ�����
    int32                field_slot ;       //slot position
    uint32               decimal_place ;    //С��λ
    Fast_Value           field_opval ;      //OP Value ,<Constant value=>
    Fast_Value           field_curval ;     //�ֶεĵ�ǰֵ
    FastMsg_Templ        *seq_ptr ;         //�����ֶ���Sequence���͵�,���ֶα�����ģ��

    Fast_TemplField()
    { 
	    memset(this, 0, sizeof(*this)); 
	    field_slot=-1;  
	    ResetCurrentValue();
    }
    
    void Destory() ;
    
    ~Fast_TemplField(){ Destory();}

    void ResetCurrentValue()
    {
	     field_curval.Reset();
    }
    
    bool IsAssignedCurrentValue()
    {
	     return field_curval.IsAssigned();
    }
} ;

//Fast��Ϣģ��
#define FAST_TEMPLNAME_LEN 100
typedef vector<Fast_TemplField *> Fast_Field_Array ;
struct FastMsg_Templ
{
  uint32                templ_id ;
  uint32                slot_count  ; //slot count
  uint32                field_count ; //field count
  char                  templ_name[FAST_TEMPLNAME_LEN] ; //template name
  Fast_Field_Array      field_array ; //ģ���ֶε��б�
  FastMsg_Templ():templ_id(0), slot_count(0), field_count(0) { }
  ~FastMsg_Templ()
  { 
    for(size_t i=0; i<field_array.size(); i++)
    {
      if( field_array[i]!=0 )
        delete field_array[i] ;
    }
  }
 
  int AddField(Fast_TemplField *pField)
  {
    if( pField==0 ) return -1 ;
    field_array.push_back(pField) ;
    return 0 ;
  }

  void ResetCurrentValue()
  {
	  for (size_t i = 0; i < field_array.size(); i++)
	  {
		  if (field_array[i])
		  {
			  field_array[i]->ResetCurrentValue();
		  }
	  }
  }
} ;

#define FAST_PMAPSIZE 8
typedef unsigned char PMAP[FAST_PMAPSIZE] ;

//Fastģ���
typedef map<uint32, FastMsg_Templ *> FastTempl_Map ;
class FastTempl_Manager
{
protected:
    FastTempl_Map m_mapTempl ;

public:
    ~FastTempl_Manager()
    {
        this->Clear () ;
    }

    FastMsg_Templ *GetTemplate(uint32 nTemplID)
    {
        FastTempl_Map::iterator iter = m_mapTempl.find(nTemplID) ;
        
        if( iter!= m_mapTempl.end() )
            return iter->second ;
        else
            return 0 ;
    }

    int  AddTempl(uint32 nTemplID, FastMsg_Templ *lpFastTempl)
    {
        std::pair<FastTempl_Map::iterator, bool> ret = m_mapTempl.insert(FastTempl_Map::value_type(nTemplID, lpFastTempl)) ;
        if( ret.second )
            return  0  ;
        else
        return  -1 ;
    }

    void Clear()
    {
        for(FastTempl_Map::iterator iter = m_mapTempl.begin(); iter != m_mapTempl.end(); ++iter)
        {
            FastMsg_Templ *lpTempl = iter->second ;
            if (lpTempl)
                delete lpTempl ;
            lpTempl = 0 ;
        }
        m_mapTempl.clear() ;
    }

    void Print()
    {
        char  strTemp[256+1] ;
    sprintf(strTemp, "<<<<<<Template Count:%d>>>>>>>\n", m_mapTempl.size()) ;
    printf (strTemp) ;
    for(FastTempl_Map::iterator iter = m_mapTempl.begin() ;
        iter != m_mapTempl.end() ;
        ++iter)
    {
      FastMsg_Templ* lpMsgTempl = iter->second ;
      sprintf (strTemp, "***TNAME:%s TID:%d FieldCount:%d SlotCount:%d\n",
                lpMsgTempl->templ_name,  lpMsgTempl->templ_id,
                lpMsgTempl->field_count, lpMsgTempl->slot_count ) ;
      printf (strTemp) ;
      for (size_t i = 0; i<lpMsgTempl->field_array.size(); ++i)
      {
        Fast_TemplField* lpFieldTempl = lpMsgTempl->field_array[i] ;
        sprintf (strTemp, "  %s %d\n", lpFieldTempl->field_name, lpFieldTempl->field_id) ;
        printf (strTemp) ;
      }
    }
  }
};


class Fast_Method
{
public:
    static Fast_FieldType StrToFieldType(const char *strType)
    {
        if (!strType)  return FFT_Null_Type ;
	    //  ���Դ�Сд
	    std::string tmp_str(strType);
	    strType = tmp_str.c_str();
	    for (std::string::size_type i = 0; i < tmp_str.size(); i++)
	    {
		    tmp_str[i] = tolower(tmp_str[i]);
	    }

        // ���Դ�Сд
        if (!strcmp(strType, "string"))
            return FFT_String ;
        else if (!strcmp(strType, "int32"))
            return FFT_Int32  ;
        else if (!strcmp(strType, "uint32"))
            return FFT_UInt32 ;
        else if (!strcmp(strType, "int64"))
            return FFT_UInt64 ;
        else if (!strcmp(strType, "uint64"))
            return FFT_UInt64 ;
        else if (!strcmp(strType, "sequence"))
            return FFT_Sequence ;
        else if (!strcmp(strType, "length"))
            return FFT_Length ;
        else
            return FFT_Null_Type ;
    }

    static Fast_OP StrToFastOp(const char *strType)
    {
        if (!strType)  return OP_NULL ;
        if (!strcmp(strType, "constant"))
            return OP_Constant ;
        else if (!strcmp(strType, "default"))
            return OP_Default  ;
        else if (!strcmp(strType, "copy"))
            return OP_Copy ;
        else if (!strcmp(strType, "increment"))
            return OP_Increment ;
        else if (!strcmp(strType, "delta"))
		    return OP_Delta ;
        else
            return OP_NULL ;
    }

    static Fast_Presence StrToPres(const char *strPres)
    {
        if (!strPres) return PRES_Mandatory ;

        if (!strcmp(strPres, "optional"))
            return PRES_Optional ;
        else
            return PRES_Mandatory ;
    }

    static int Slot(Fast_OP op, Fast_Presence pres)
    {
        if ((op == OP_NULL) || (op == OP_Constant && PRES_Mandatory == pres) || (op == OP_Delta && PRES_Mandatory == pres))
            return 0 ;
        else
            return 1 ;
    }
};

#endif
