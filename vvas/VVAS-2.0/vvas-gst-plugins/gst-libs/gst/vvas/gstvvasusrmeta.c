/*
 * Copyright 2022 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gstvvasusrmeta.h>

GType
gst_vvas_usr_meta_api_get_type (void)
{
  static GType type = 0;
  static const gchar *tags[] = { GST_META_TAG_VIDEO_STR, NULL
  };

  if (g_once_init_enter (&type)) {
    GType _type = gst_meta_api_type_register ("GstVvasUsrMetaAPI", tags);
    g_once_init_leave (&type, _type);
  }

  return type;
}

static gboolean
gst_vvas_usr_meta_init (GstMeta * meta, gpointer params, GstBuffer * buffer)
{
  GstVvasUsrMeta *vvasmeta = (GstVvasUsrMeta *) meta;

  vvasmeta->copy_func = NULL;
  vvasmeta->release_func = NULL;
  vvasmeta->usr_data = NULL;

  return TRUE;
}


static gboolean
gst_vvas_usr_meta_free (GstMeta * meta, GstBuffer * buffer)
{
  GstVvasUsrMeta *vvasmeta = (GstVvasUsrMeta *) meta;

  if (vvasmeta && vvasmeta->usr_data && vvasmeta->release_func)
    vvasmeta->release_func (vvasmeta->usr_data);

  return TRUE;
}


static gboolean
gst_vvas_usr_meta_transform (GstBuffer * dest, GstMeta * meta,
    GstBuffer * buffer, GQuark type, gpointer data)
{
  GstVvasUsrMeta *vvasmeta;
  void *usrdata;

  if (GST_META_TRANSFORM_IS_COPY (type)) {

    vvasmeta = (GstVvasUsrMeta *) meta;
    if (vvasmeta && vvasmeta->usr_data && vvasmeta->copy_func) {
      usrdata = vvasmeta->copy_func (vvasmeta->usr_data);
      gst_buffer_add_vvas_usr_meta (dest, vvasmeta->copy_func,
          vvasmeta->release_func, usrdata);
    }
  } else {
    GST_ERROR ("Unsupported transform type : %s", g_quark_to_string (type));
    return FALSE;
  }

  return TRUE;
}

const GstMetaInfo *
gst_vvas_usr_meta_get_info (void)
{
  static const GstMetaInfo *vvas_usr_meta_info = NULL;

  if (g_once_init_enter ((GstMetaInfo **) & vvas_usr_meta_info)) {
    const GstMetaInfo *meta =
        gst_meta_register (GST_VVAS_USR_META_API_TYPE, "GstVvasUsrMeta",
        sizeof (GstVvasUsrMeta),
        (GstMetaInitFunction) gst_vvas_usr_meta_init,
        (GstMetaFreeFunction) gst_vvas_usr_meta_free,
        gst_vvas_usr_meta_transform);
    g_once_init_leave ((GstMetaInfo **) & vvas_usr_meta_info,
        (GstMetaInfo *) meta);
  }
  return vvas_usr_meta_info;
}

GstVvasUsrMeta *
gst_buffer_add_vvas_usr_meta (GstBuffer * buffer, VvasUsrMetaCopyFunc copy_func,
    VvasUsrMetaReleaseFunc release_func, void *usr_data)
{
  GstVvasUsrMeta *meta;
  g_return_val_if_fail (GST_IS_BUFFER (buffer), NULL);
  meta = (GstVvasUsrMeta *) gst_buffer_add_meta (buffer,
      GST_VVAS_USR_EXAMPLE_META_INFO, NULL);

  meta->copy_func = (VvasUsrMetaCopyFunc) copy_func;
  meta->release_func = (VvasUsrMetaReleaseFunc) release_func;
  meta->usr_data = (void *) usr_data;
  return meta;
}
