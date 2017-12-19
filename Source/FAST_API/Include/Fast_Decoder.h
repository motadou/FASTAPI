#ifndef HUNDSUN_PUBLIC_FAST_DECODER_H
#define HUNDSUN_PUBLIC_FAST_DECODER_H

#include "Basic_Types.h"

//ValueType
enum ValueType
{
  emInt8   ,
  emUInt8  ,
  emInt16  ,
  emUInt16 ,
  emInt32  ,
  emUInt32 ,
  emInt64  ,
  emUInt64 ,
  emString ,
  emSequence
} ;

/***
 *@struct FastField_Info
 *������FAST�ֶε�����
 **/
struct FastField_Info
{
  ValueType      emType ;            // ֵ����
  int            nDecimalPlaces ;    // С��λ
  char           strDesc [32] ;      // �ֶ�����
} ;


/***
 * @class IFast_Record
 */
class IFast_Record
{
public:

  virtual ~IFast_Record () {}
  /***
   *@method GetInt8
   *@func   ��ȡ8-bits���ֶ�ֵ
   *@param
   *   nTagID: Fast Field TagID
   *@return
   *   value of a 8-bit int field.
   *   0: field may be not exist. Call IsExist() to confirm.
   */
  virtual uint8 FUNCTION_CALL_MODE GetInt8 (int nTagID) = 0 ;
  
  /***
   *@method GetInt8
   *@func   ��ȡ16-bits���ֶ�ֵ
   *@param
   *   nTagID: Fast Field TagID
   *@return
   *   value of a 16-bit int field.
   *   0: field may be not exist. Call IsExist() to confirm.
   */
  virtual uint16 FUNCTION_CALL_MODE GetInt16 (int nTagID)  = 0 ;
  
  /***
   *@method GetInt32
   *@func   ��ȡ16-bits���ֶ�ֵ
   *@param
   *   nTagID: Fast Field TagID
   *@return
   *   value of a 32-bit int field.
   *   0: field may be not exist. Call IsExist() to confirm.
   */
  virtual uint32 FUNCTION_CALL_MODE GetInt32 (int nTagID) = 0 ;
  
  /***
   *@method GetInt64
   *@func   ��ȡ64-bits���ֶ�ֵ
   *@param
   *   nTagID: Fast Field TagID
   *@return
   *   value of a 64-bit int field.
   *   0: field may be not exist. Call IsExist() to confirm.
   */
  virtual uint64 FUNCTION_CALL_MODE GetInt64 (int nTagID) = 0 ;

  /***
   *@method GetString
   *@func   ��ȡString���ֶ�ֵ
   *@param
   *   nTagID: Fast Field TagID
   *@return
   *   value of a string field.
   *   0: field may be not exist. Call IsExist() to confirm.
   */
  virtual const char* FUNCTION_CALL_MODE GetString (int nTagID) = 0 ;

  /***
   *@method IsExist
   *@func   �ж�ĳ���ֶ��Ƿ����
   *@param
   *   nTagID: Fast Field TagID
   *@return
   *   false: not exist.
   *   true : exist.
   */
  virtual bool FUNCTION_CALL_MODE IsExist (int nTagID)   = 0 ;

   /***
   *@method GetSubCount
   *@func   ��ĳ���ֶ�ΪSequenceʱ,���ô˷�����ȡ���µļ�¼��
   *@param
   *   nTagID: TagID of A Sequence Field.
   *@return
   *   0: field not exist.
   *  >0: record count. 
   */
  virtual int FUNCTION_CALL_MODE GetSubCount (int nTagID) = 0 ;

  /***
   *@method GetSubRecord
   *@func   ��ȡĳ��Sequence�ֶ��µ�ĳ��FAST��¼
   *@param
   *   nTagID: TagID of A Sequence Field.
   *   nSlot: 0...GetSeqCount ()-1
   *@return
   *   Nonzero: succ
   *   0: error. 
   */
  virtual IFast_Record* FUNCTION_CALL_MODE GetSubRecord (int nTagID, int nSlot) = 0 ;
} ;


/***
 * @class IFast_Message
 */
class IFast_Message
{
public:
  virtual ~IFast_Message () {}
  /***
   *@method GetMsgType
   *@func   ��ȡ��Ϣ����.
   *@return
   *   0: null message.
   */
  virtual const char* FUNCTION_CALL_MODE GetMsgType () = 0 ;

  /***
   *@method GetSendTime
   *@func   ��ȡ����ʱ��.
   *@return
   *   0: null message.
   */
  virtual const char* FUNCTION_CALL_MODE GetSendTime () = 0 ;

  /***
   *@method GetSeqNum
   *@func   ��ȡ��Ϣ���.
   *@return
   *   -1: null message.
   */
  virtual int FUNCTION_CALL_MODE GetSeqNum () = 0 ;

  /***
   *@method GetRecordCount
   *@func   ��ȡFAST��¼�ĸ���
   *@return
   *   >0: record count
   *   -1: error. Call GetLastError() to get error info.
   */
  virtual int FUNCTION_CALL_MODE GetRecordCount () = 0 ;

  /***
   *@method GetRecord
   *@func   ��ȡFAST��¼
   *@param
   *   nSlot: 0...GetRecordCount ()
   *@return
   *   Nonzero: succ
   *   0: error. Call GetLastError() to get error info.
   */
  virtual IFast_Record* FUNCTION_CALL_MODE GetRecord (int nSlot) = 0 ;

  /***
   *@method GetLastError
   *@func   ��ȡ���Ĵ�����Ϣ
   *@return
   *     0: no error.
   * other: error info.
   */
  virtual const char* FUNCTION_CALL_MODE GetLastError () = 0 ;

  /***
   *@method Release
   *@func   �ͷ���Ϣ.
   */
  virtual void FUNCTION_CALL_MODE Release () = 0 ;
} ;


/***
 * @class IFast_Decorder
 * @func  Interface for decoding fast message.
 */
class IFast_Decoder
{
public:
  virtual ~IFast_Decoder () {}
  /***
   *@method LoadTemplate
   *@func   ����FASTģ���ļ�
   *@param
   *   lpFile: template file name
   *@return
   *   0: succ
   */
  virtual int FUNCTION_CALL_MODE LoadTemplate (const char* lpFile) = 0 ;

  /***
   *@method LoadTemplate
   *@func   ����FASTģ���ļ��������������ģ�壩
   *@param
   *   lpFile: template file name
   *@return
   *   0: succ
   */
  virtual int FUNCTION_CALL_MODE LoadTemplateForSZG5HQ (const char* lpFile) = 0 ;

  /***
   *@method GetFastMsgLen
   *@func   ��ȡһ������FAST��Ϣ�ĳ���
   *@param
   *   lpData: Received buffer
   *   nLen  : Received size
   *@return
   *   -1: error. Call LastErr() to get error info.
   *    0: buffer is not enough.
   *   >0: size of a complete fast message.
   */
  virtual int FUNCTION_CALL_MODE GetFastMsgLen (const char* lpData, int nLen) = 0 ;

  /***
   *@method Decode
   *@func   ����һ��������FAST��Ϣ.һ����Step��Ϣ����
   *@param
   *   lpData: fast data of a complete fast message. 
   *   nLen:   length of fast message.
   *@return
   *   0: error. Call GetLastError() for detailed error.
   * !=0: succ. Call Release() after used.
   */
  virtual IFast_Message* FUNCTION_CALL_MODE Decode (const char* lpData, int nLen) = 0 ;

  /***
   *@method DecodeFastData
   *@func   ����һ��������FAST��Ϣ.Fast����������
   *@param
   *   lpData: fast data of a complete fast message. 
   *   nLen:   length of fast message.
   *   nMsgType  message type (template id)
   *@return
   *   0: error. Call GetLastError() for detailed error.
   * !=0: succ. Call Release() after used.
   */
  virtual IFast_Message* FUNCTION_CALL_MODE DecodeFastData (const char* lpFastData, int nFastDataLen,int nMsgType) = 0 ;


  /***
   *@method DecodeFastData
   *@func   ����һ��������FAST��Ϣ.Fast���������� (���ڵ��������)
   *@param
   *   lpData: fast data of a complete fast message. 
   *   nLen:   length of fast message.
   *@return
   *   0: error. Call GetLastError() for detailed error.
   * !=0: succ. Call Release() after used.
   */
  virtual IFast_Message* FUNCTION_CALL_MODE DecodeFastData (const char* lpFastData, int nFastDataLen) = 0 ;



  /***
   *@method GetFieldInfo
   *@func   ��ȡĳ��FAST�ֶε���Ϣ
   *@param
   *   nTagID: tagid of a fast field.
   *@return
   *     0: no [nTagID]field.
   */
  virtual const FastField_Info* FUNCTION_CALL_MODE GetFieldInfo (int nTagID) = 0 ;

    /***
     *@method GetLastError
     *@func   ��ȡ���Ĵ�����Ϣ
     *@return
     *     0: no error.
     * other: error info.
     */
    virtual const char* FUNCTION_CALL_MODE GetLastError () = 0 ;

    /***
     *@method Release
     *@func   �ͷŽ�����.
     */
    virtual void FUNCTION_CALL_MODE Release () = 0 ;
} ;

#endif