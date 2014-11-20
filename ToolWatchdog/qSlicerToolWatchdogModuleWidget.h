/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

#ifndef __qSlicerToolWatchdogModuleWidget_h
#define __qSlicerToolWatchdogModuleWidget_h

// SlicerQt includes
#include "qSlicerAbstractModuleWidget.h"

#include "qSlicerToolWatchdogModuleExport.h"



class QTimer;
class qSlicerToolWatchdogModuleWidgetPrivate;
class vtkMRMLNode;
//class QHash;
 #include <QHash>

/// \ingroup Slicer_QtModules_ExtensionTemplate
class Q_SLICER_QTMODULES_TOOLWATCHDOG_EXPORT qSlicerToolWatchdogModuleWidget :
  public qSlicerAbstractModuleWidget
{
  Q_OBJECT

public:

  typedef qSlicerAbstractModuleWidget Superclass;
  qSlicerToolWatchdogModuleWidget(QWidget *parent=0);
  virtual ~qSlicerToolWatchdogModuleWidget();

  void SetCurrentNode( vtkMRMLNode* currentNode );

public slots:

  virtual void setMRMLScene( vtkMRMLScene* scene );
  void onSceneImportedEvent();

protected slots:

  void onModuleNodeChanged();

  void onTransformChanged();
  void UpdateFromMRMLNode();
  void OnTimeout();

  void onDeleteButtonClicked();
  void onTransformNodeAdded( );
  void onTransformsTableContextMenu(const QPoint& position);
  void updateWidget();
  //void onTransformsEdited( int row, int column );


protected:
  QScopedPointer<qSlicerToolWatchdogModuleWidgetPrivate> d_ptr;

  void updateTable();
  virtual void setup();
  virtual void enter();

private:
  Q_DECLARE_PRIVATE(qSlicerToolWatchdogModuleWidget);
  Q_DISABLE_COPY(qSlicerToolWatchdogModuleWidget);

  QTimer* Timer;

  QHash<QString, int> * TransformRowNumberHash;


};

#endif
