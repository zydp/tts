/************************************************************************
˵�����������Ŀ���к궨���ļ�
���ߣ��С��
���ڣ�2007��10��15
�޸ģ�
��¼��
************************************************************************/

#ifndef G3P2P_MACRO_DEFINE_H
#define G3P2P_MACRO_DEFINE_H

//������Ķ���
#if (defined(_WIN32) || defined(__CYGWIN__)) && defined(G3P2P_DLL)
#if defined(G3P2P_EXPORTS)
#define G3P2P_API __declspec(dllexport)
#else
#define G3P2P_API __declspec(dllimport)
#endif
#endif

#if !defined(G3P2P_API)
#define G3P2P_API
#endif

//��������
#define G3P2P_BEGIN namespace G3P2P_BY_LONGYU {
#define G3P2P_END   }

#endif
