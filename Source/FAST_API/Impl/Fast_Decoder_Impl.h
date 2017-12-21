/*
 * =====================================================================================
 *
 *   Filename: Fast_Decoder_Impl
 *   Company:   hundsun
 *   Copyrigth: hundsun
 *   
 *   Version:  
 *   Date: 20140214
 *   Compiler:  
 *
 *   Author:  ��ģ��
 *        
 *   Describ�� �����Ϻ�������Fast��Ϣ
 *
 *  @tangmc 20140704 
 *  1������ DecodeFastData              ֱ������FAST���ݵĽ����ӿ�
 *          
 *			DecodeFastForNotMsgType         ����Fast����û�д�����Ϣ����
 *          DecodeFastRecordForNotMsgType    ����Fast����û�д�����Ϣ����
 *  @tangmc 20141126 
 *   1������UStringLength���� Fast_Presence pres ����������
 * =====================================================================================
 */
#ifndef HUNDSUN_FAST_DECODER_SH_H
#define HUNDSUN_FAST_DECODER_SH_H

#include "../Include/Fast_Decoder.h"
#include "Fast_Define.h"
#include "TinyXML/tinyxml.h"
#include "Fast_Record_Impl.h"
#include "Fast_Message_Impl.h"
#include <map>

class Fast_Decoder_Impl : public IFast_Decoder
{
public:
    Fast_Decoder_Impl (FAST_TYPE makettype) ;

    virtual int FUNCTION_CALL_MODE LoadTemplate (const char* lpFile) ;

    virtual int FUNCTION_CALL_MODE LoadTemplateForSZG5HQ (const char* lpFile);

    virtual int FUNCTION_CALL_MODE GetFastMsgLen (const char* lpData, int nLen) ;

    virtual IFast_Message* FUNCTION_CALL_MODE Decode (const char* lpData, int nLen) ;

    virtual IFast_Message* FUNCTION_CALL_MODE DecodeFastData (const char* lpFastData, int nFastDataLen,int nMsgType);

    virtual IFast_Message* FUNCTION_CALL_MODE DecodeFastData (const char* lpFastData, int nFastDataLen);

    virtual const FastField_Info* FUNCTION_CALL_MODE GetFieldInfo (int nTagID) ;

    virtual const char* FUNCTION_CALL_MODE GetLastError () ;

    virtual void FUNCTION_CALL_MODE Release () ;

protected:
    FastTempl_Manager                 m_FastTempls ;
    std::map<int, Fast_TemplField *>  m_mapFieldInfo ;

    char                              m_strError [256] ;
    bool                              m_bHasError ;
    FAST_TYPE m_makettype;

    virtual FastMsg_Templ* LoadTemplate (TiXmlElement *pXmlElement) ;

    virtual Fast_TemplField* LoadFieldTempl (TiXmlElement *pXmlElement) ;

    // ����FAST-Data
    virtual int DecodeFast (const char* lpData, int nLen, Fast_Message_Impl* lpFastMsg, FastMsg_Templ* lpMsgTempl);
    virtual int DecodeFastRecord (const char* lpData, int nLen, Fast_Record_Impl* lpRecord, FastMsg_Templ* lpMsgTempl) ;

    //����Fast����û�д�����Ϣ����
    int DecodeFastForNotMsgType (const char* lpData, int nLen, Fast_Message_Impl* lpFastMsg) ;

    //����Fast����û�д�����Ϣ����
    virtual FastMsg_Templ* DecodeFastRecordForNotMsgType (const char* lpFastData, int nDataLen, Fast_Record_Impl* lpRecord,int &nOffset) ;

  //����Sequence�ĸ���
  size_t DecodeSequenceCount(const char* lpfast_data, uint32& nCount, const Fast_Presence& pres) ;
 
  //2013-02-18 tangmc ���Ϻ����ڷֿ�
  //����һ��sequence
  size_t DecodeSequenceSH (FastGroup *lpGroup, const char *lpFastData, size_t nDataLen, FastMsg_Templ *lpMsgTempl) ;
  //����һ��sequence�� IGroup
  size_t DecodeSequenceSZ (FastGroup *lpGroup, const char *lpFastData, size_t nDataLen, Fast_TemplField *lpField/*FastMsg_Templ *lpMsgTempl*/) ;
  //2013-02-18 tangmc ���Ϻ����ڷֿ�

  //����һ��Fast_Value��IRecord��
  int SetFastValRecord (Fast_Record_Impl *lpRecord, uint32& nID, const Fast_Value& fast_val) ;

  //����PMAP
  size_t DecodePMAP (const char* lpData, size_t nDataLen, PMAP pmap) ;
  //����FAST��Ϣ����
  size_t DecodeFastType (const char* lpData, uint32& nMsgType) ;
  //����FAST�ֽڻ��һ���ֶ�	
  size_t DecodeBytes (const char* lpData, char* lpBuf, size_t nDataLen) ;
  //����int32����
  size_t DecodeInt32 (const char* lpData, Fast_Presence pres, Fast_Value& fast_val) ;
  //����int64����
  size_t DecodeInt64 (const char* lpData, Fast_Presence pres, Fast_Value& fast_val) ;
  //����string����
  size_t DecodeString (const char* lpData, Fast_Presence pres, Fast_Value& fast_val) ;
  // ����unicode string
  size_t DecodeUString(const char *lpData, Fast_Presence pres, Fast_Value &fast_val);
  // ����unicode string�ĳ��� //20141126 tangmc ���Ӳ�����
  size_t DecodeUStringLength(const char *lpData, uint32 &nLen, Fast_Presence pres);

  //��ȡpmap�ĵ�loc��bit
  int GetPMAPBit(const PMAP pmap, uint32 loc) ;
  //�ж��ֶε�ֵ�Ƿ����������
  bool IsExistField (const FastMsg_Templ* lpMsgTempl, const  PMAP pmap, uint32 pos) ;
  bool IsExistInSeq (const FastMsg_Templ* lpMsgTempl, const  PMAP pmap, uint32 pos) ;
  //����NORMAL�ֶ�
  size_t DecodeNormalField (const char* lpData, const FastMsg_Templ* lpMsgTempl, 
                                   const PMAP pmap, uint32 pos, Fast_Value &fast_val) ;
  //�����ֶ�ֵ
  size_t DecodeFieldValue (const char* lpData, Fast_Value& fast_val, Fast_Presence pres) ;

  //�õ�ĳһSTEP�ֶ�ֵ
  std::string get_step_field_value(const char *buf, int len, const std::string &field_name);

  std::string UTF8_To_GBK(const std::string& utf8_str);

} ;

#endif